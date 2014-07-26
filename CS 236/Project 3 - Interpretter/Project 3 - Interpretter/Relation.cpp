#include "Relation.h"


Relation::Relation()
{
}

Relation::Relation(Predicate scheme){
	Scheme newScheme(scheme);
	myScheme = newScheme;
	name = scheme.name;
	varInQuery = false;
}

Relation::~Relation()
{
}

void Relation::select(int index, string value){
	set<Tuple>::iterator iter = myTuples.begin();
	while (iter != myTuples.end()){
		Tuple temp = *iter;
		if (temp[index] != value){
			iter = myTuples.erase(iter);
		}
		else{
			iter++;
		}
	}
}

void Relation::select(int index1, int index2){
	set<Tuple>::iterator iter;
	for (iter = myTuples.begin(); iter != myTuples.end(); iter++){
		Tuple temp = *iter;
		if (temp[index1] != temp[index2]){
			myTuples.erase(iter);
		}
	}
}

void Relation::project(){

}

void Relation::rename(string oldCol, string newCol){
	for (int i = 0; i < myScheme.names.size(); i++){
		if (myScheme.names[i] == oldCol){
			myScheme.names[i] = newCol;
		}
	}
}

string Relation::toString(Predicate query){
	string result = query.toString()+"? ";
	if (myTuples.size() == 0){
		result += "No";
	}
	else {
		result += "Yes(" + itos(myTuples.size()) + ")";
		if (varInQuery){
			result += "\n  ";
			set<Tuple>::iterator iter = myTuples.begin();
			while (iter != myTuples.end()){
				Tuple temp = *iter;
				for (int k = 0; k < myScheme.names.size(); k++){
					result += myScheme.names[k] + "='" + temp[k] + "', ";
				}
				iter++;
				result = result.substr(0, (result.length() - 2)) + "\n  ";
			}
			result = result.substr(0, result.length() - 4);
		}
	}
	return result;
}
