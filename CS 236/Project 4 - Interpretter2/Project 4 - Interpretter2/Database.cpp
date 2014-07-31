#include "Database.h"
#include <utility>


Database::Database()
{
}


Database::Database(DatalogProgram dp){
	ruleIterations = 0;
	makeDB(dp);
}


Database::~Database()
{
}

void Database::makeDB(DatalogProgram dp){
	addRelations(dp);
	addTuples(dp);
	addRules(dp);
}

set<pair<int,int>> Database::sameIndex(Relation r1, Relation r2){
	set<pair<int,int>> myPairs;
	for (int index1 = 0; index1 < r1.myScheme.names.size(); index1++){
		for (int index2 = 0; index2 < r2.myScheme.names.size(); index2++){
			if (r1.myScheme.names[index1] == r2.myScheme.names[index2]){
				pair<int, int> newPair = make_pair(index1, index2);
				myPairs.insert(newPair);
			}
		}
	}
	return myPairs;
}

bool Database::canJoin(set<pair<int,int>> pairs, Tuple t1, Tuple t2){
	bool canJoin = true;
	for (set<pair<int, int>>::iterator iter = pairs.begin(); iter != pairs.end(); iter++){
		pair<int, int> temp = *iter;
		if (t1[temp.first] != t2[temp.second]){
			canJoin = false;
			break;
		}
	}
	return canJoin;
}

Tuple Database::joinTuple(set<pair<int, int>> pairs, Tuple t1, Tuple t2){
	Tuple newTuple;
	for (int i = 0; i<t1.size(); i++){
		newTuple.push_back(t1[i]);
	}
	for (int i = 0; i<t2.size(); i++){
		if (pairs.size() >0){
			for (set<pair<int, int>>::iterator iter = pairs.begin(); iter != pairs.end(); iter++){
				pair<int, int> temp = *iter;
				if (i != temp.second){
					newTuple.push_back(t2[i]);
				}
			}
		}
		else {
			newTuple.push_back(t2[i]);
		}
	}
	return newTuple;
}

set<Tuple> Database::joinTuples(set<Tuple> r1tup, set<Tuple> r2tup, set<pair<int,int>> myPairs){
	set<Tuple> newSet;
	for (set<Tuple>::iterator iter2 = r1tup.begin(); iter2 != r1tup.end(); iter2++){
		for (set<Tuple>::iterator iter3 = r2tup.begin(); iter3 != r2tup.end(); iter3++){
			if (canJoin(myPairs,*iter2, *iter3)){
				newSet.insert(joinTuple(myPairs,*iter2, *iter3));
			}
		}
	}
	return newSet;
}

vector<int> Database::getProjectIndex(Predicate ruleHead, Relation rel){
	vector<int> newVector;
	for (int i = 0; i < ruleHead.myParams.size(); i++){
		for (int k = 0; k < rel.myScheme.names.size(); k++){
			if (ruleHead.myParams[i].getName()==rel.myScheme.names[k]){
				newVector.push_back(k);
				break;
			}
		}
	}
	return newVector;
}

int Database::getSize(){
	int count = 0;
	for (map<string, Relation>::iterator iter = myRelations.begin(); iter != myRelations.end(); iter++){
		Relation myRel = myRelations[iter->first];
		count += myRel.myTuples.size();
	}
	return count;
}

Relation Database::ruleRelation(Predicate pred){
	Relation temp = myRelations[pred.name];
	for (int i = 0; i < pred.myParams.size(); i++){
		if (pred.myParams[i].isName()){
			//rename variable
			temp.rename(i, pred.myParams[i].getName());
		}
		else {
			temp.select(i, pred.myParams[i].getValue());
		}
	}
	return temp;
}

void Database::addRules(DatalogProgram dp){
	int oldSize = 0;
	while (oldSize != getSize()){
		oldSize = getSize();
		ruleIterations++;
		for (int i = 0; i < dp.rules.size(); i++){
			Rule rule = dp.rules[i];
			Relation r1 = ruleRelation(rule.body[0]);
			if (rule.body.size() > 1){
				for (int k = 1; k < rule.body.size(); k++){
					Relation r2 = ruleRelation(rule.body[k]);
					set<pair<int, int>> myIndexes = sameIndex(r1, r2);
					set<Tuple> r1Tup = r1.myTuples;
					set<Tuple> r2Tup = r2.myTuples;
					r1 = r1.join(r2);

					r1.myTuples = joinTuples(r1Tup, r2Tup, myIndexes);

				}
			}
			r1.project(getProjectIndex(rule.head, r1));
			insertNewTuples(rule.head.name, r1);
		}
	}
}

void Database::insertNewTuples(string name, Relation rel){
	for (set<Tuple>::iterator iter = rel.myTuples.begin(); iter != rel.myTuples.end(); iter++){
		myRelations[name].myTuples.insert(*iter);
	}

}

void Database::addRelations(DatalogProgram dp){
	for (int i = 0; i < dp.schemes.size(); i++){
		Relation newRelation(dp.schemes[i]);
		myRelations[newRelation.name] = newRelation;
	}

}

void Database::addTuples(DatalogProgram dp){
	for (int i = 0; i < dp.facts.size(); i++){
		Tuple newTuple(dp.facts[i]);
		myRelations[dp.facts[i].name].myTuples.insert(newTuple);
	}
}
