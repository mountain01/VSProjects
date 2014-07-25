#pragma once
#include "Parser.h"
#include "Relation.h"
#include <map>
using namespace std;

class Database
{
private:
	map<string, Relation> myRelations;

public:
	Database();
	Database(string fileName);
	Database(char* filename);
	~Database();

	void makeDB(DatalogProgram dp);
	void addRelations(DatalogProgram dp);
	void addTuples(DatalogProgram dp);
};

