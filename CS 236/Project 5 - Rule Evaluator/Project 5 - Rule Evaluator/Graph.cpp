#include "Graph.h"


Graph::Graph()
{
}

Graph::Graph(DatalogProgram dp){
	int qCount = 1;
	int rCount = 1;
	for (auto query : dp.queries){
		string id = "Q" + itos(qCount++);
		Node newNode(query, id, dp.rules);
		Nodes[id] = newNode;
	}
	for (auto rule : dp.rules){
		string id = "R" + itos(rCount++);
		Node newNode(rule, id, dp.rules);
		Nodes[id] = newNode;
	}
}


Graph::~Graph()
{
}

string Graph::toString(){
	string result = "";
	for (auto node : Nodes){
		result += node.second.toString();
	}
	return result;
}
