#pragma once
#include "Database.h"
#include "Parser.h"
#include "Graph.h"
using namespace std;

class Interpretter
{
private:
	Database myDb;
	DatalogProgram myDP;
	string result;
	Graph myGraph;
public:
	Interpretter();
	Interpretter(char* filename);
	~Interpretter();
	void testQueries();
	string toString();
};

