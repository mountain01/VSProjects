#pragma once
#include "Node.h"
#include "DatalogProgram.h"
#include <map>
using namespace std;
class Graph
{
public:
	map<string, Node> Nodes;
	Graph();
	Graph(DatalogProgram dp);
	~Graph();
	string toString();
};

