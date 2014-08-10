#pragma once
#include <set>
#include <string>
#include "Predicate.h"
#include "Rule.h"
#include "Util.h"
using namespace std;
class Node
{
public:
	set<string> neighbors;
	string id;
	string name;
	bool marked;
	int postOrder;
	Node();
	Node(Predicate item, string newId, vector<Rule> rules);
	Node(Rule rule, string newId, vector<Rule> rules);
	~Node();
	void setAdjacent(Predicate pred, vector<Rule> rules);
};

