#include "Database.h"


Database::Database()
{
}


Database::Database(DatalogProgram dp){
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

void Database::addRules(DatalogProgram dp){
	for (int i = 0; i < dp.rules.size(); i++){
		Rule rule = dp.rules[i];
		Relation r1 = myRelations[rule.body[0].name];
		set<Tuple> r1Tup = r1.myTuples;
		if (rule.body.size() > 1){
			for (int k = 1; k < rule.body.size(); k++){
				Relation r2 = myRelations[rule.body[k].name];
				set<Tuple> r2Tup = r2.myTuples;
				r1 = r1.join(r2);

				Tuple newTuple(r1.mySceme, r1TUp, r2Tup);
			}

		}
	}


	/*make the scheme s for the result relation
		(combine r1's scheme with r2's scheme)

		make a new empty relation r using scheme s

	for each tuple t1 in r1
	for each tuple t2 in r2

	if t1 and t2 can join
		join t1 and t2 to make tuple t
		add tuple t to relation r
		end if

		end for
		end for*/

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
