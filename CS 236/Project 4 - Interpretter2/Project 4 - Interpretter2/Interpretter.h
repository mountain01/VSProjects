#pragma once
#include "Database.h"
#include "Parser.h"
using namespace std;

class Interpretter
{
private:
	Database myDb;
	DatalogProgram myDP;
	string result;
public:
	Interpretter();
	Interpretter(char* filename);
	~Interpretter();
	void testQueries();
	string toString();
};

