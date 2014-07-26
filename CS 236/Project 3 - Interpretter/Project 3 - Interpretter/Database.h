#pragma once
#include "Parser.h"
#include "Relation.h"
#include <map>
using namespace std;

class Database
{
public:
	map<string, Relation> myRelations;

	Database();
	Database(DatalogProgram dp);
	~Database();

	void makeDB(DatalogProgram dp);
	void addRelations(DatalogProgram dp);
	void addTuples(DatalogProgram dp);
};

