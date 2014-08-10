#include "Node.h"


Node::Node()
{
}

Node::Node(Predicate item, string newId, vector<Rule> rules){
	name = item.toString();
	id = newId;
	setAdjacent(item, rules);
}


Node::Node(Rule rule, string newID, vector<Rule> rules){
	name = rule.toString();
	id = newID;
	for (auto part : rule.body){
		setAdjacent(part, rules);
	}
}


Node::~Node()
{
}

void Node::setAdjacent(Predicate pred, vector<Rule> rules){
	int rCount = 1;
	for (auto rule : rules){
		string id = "R" + itos(rCount++);
		if (pred.name == rule.head.name){
			neighbors.insert(id);
		}
	}
}
