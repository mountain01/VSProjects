#include "Interpretter.h"
#include <iostream>


Interpretter::Interpretter()
{
}

Interpretter::Interpretter(char* filename){
	Parser newParser(filename);
	newParser.parse();
	myDP = newParser.getDP();
	Database newDB(myDP);
	myDb = newDB;
	result = "";
	Graph newGraph(myDP);
	myGraph = newGraph;
}


Interpretter::~Interpretter()
{
}
void Interpretter::evaluateQuery(Predicate query){
	Relation temp = myDb.myRelations[query.name];
	vector<int> positions;
	for (int k = 0; k < query.myParams.size(); k++){
		//select
		if (query.myParams[k].isName()){
			//name
			temp.varInQuery = true;
			//rename variable
			temp.rename(k, query.myParams[k].getName());
			positions.push_back(k);

		}
		else{
			//value
			temp.select(k, query.myParams[k].getValue());
		}
	}
	//project
	temp.project(positions);
	result += temp.toString(query) + "\n\n";

}

void Interpretter::DFS(Node query, int& postOrder){
	myGraph.Nodes[query.id].marked = true;

	for (auto node : query.neighbors){
		Node nextNode = myGraph.Nodes[node];
		if (!nextNode.marked){
			DFS(nextNode,postOrder);
		}
	}
	myGraph.Nodes[query.id].postOrder = postOrder++;
}

void Interpretter::resetGraph(){
	for (auto node : myGraph.Nodes){
		myGraph.Nodes[node.first].marked = false;
		myGraph.Nodes[node.first].postOrder = 0;
	}
}

void Interpretter::evaluateRules(bool backEdge, map<int, string> order){
	result += "  Rule Evaluation\n";
	vector<Rule> rules;
	for (auto num : order){
		if (num.first != order.size()){
			int test = stoi(num.second.substr(1));
			rules.push_back(myDP.rules[--test]);
		}
	}
	int oldSize = 0;
	if (backEdge){
		do{
			oldSize = myDb.getSize();
			evaluateRule(rules);
		} while (oldSize != myDb.getSize());
	}
	else {
		evaluateRule(rules);
	}
	result += "\n";

}

void Interpretter::evaluateRule(vector<Rule> rules){
	for (auto rule : rules){
		result += "    " + rule.toString() + "\n";
		myDb.interpretRule(rule);
	}
}

void Interpretter::testQueries(){
	int qCount = 1;
	for (auto query : myDP.queries){
		map<int, string> temp;
		int postOrder = 1;
		string id = "Q" + itos(qCount++);
		resetGraph();
		result += query.toString() + "?\n\n";
		DFS(myGraph.Nodes[id],postOrder);
		//temp = outputPostOrder();
		//backEdges();
		evaluateRules(backEdges(),outputPostOrder());
		evaluateQuery(query);
	}
	result = result.substr(0, result.length() - 1);
}

map<int, string> Interpretter::outputPostOrder(){
	result += "  Postorder Numbers\n";
	map<int, string> tempMap;
	for (auto node : myGraph.Nodes){
		if (node.second.marked){
			result += "    " + node.second.id + ": " 
				+ itos(node.second.postOrder) + "\n";
			tempMap[node.second.postOrder] = node.second.id;
		}
	}
	result += "\n  Rule Evaluation Order\n";
	for (auto num : tempMap){
		if (num.first != tempMap.size()){
			result += "    " + num.second + "\n";
		}
	}
	result += "\n";
	return tempMap;
}

bool Interpretter::backEdges(){
	map<string, set<string>> tempMap;
	for (auto node : myGraph.Nodes){
		if (node.second.marked){
			for (auto id : node.second.neighbors){
				if (myGraph.Nodes[node.first].postOrder <= myGraph.Nodes[id].postOrder){
					tempMap[node.first].insert(id);
				}
			}
		}
	}
	result += "  Backward Edges\n";
	for (auto node : tempMap){
		result += "    " + node.first + ":";
		for (auto id : node.second){
			result += " " + id;
		}
		result += "\n";
	}
	result += "\n";

	return tempMap.size() > 0;
}

string Interpretter::toString(){
	result += "Dependency Graph\n" + myGraph.toString() + "\n";
	testQueries();
	return result;
}