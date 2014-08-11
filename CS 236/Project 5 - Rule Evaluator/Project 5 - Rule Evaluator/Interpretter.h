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
	void evaluateQuery(Predicate query);
	void DFS(Node query, int& postOrder);
	void resetGraph();
	map<int, string> outputPostOrder();
	bool backEdges();
	void evaluateRules(bool backEdge, map<int, string> order);
	void evaluateRule(vector<Rule> rules);
};

