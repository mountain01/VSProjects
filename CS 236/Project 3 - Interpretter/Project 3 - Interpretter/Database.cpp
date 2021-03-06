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
