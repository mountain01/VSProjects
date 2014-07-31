#pragma once
#include "Predicate.h"
#include "Rule.h"
#include <set>
class DatalogProgram
{
public:
	vector<Predicate> schemes;
	vector<Predicate> facts;
	vector<Predicate> queries;
	vector<Rule> rules;
	set<string> domain;
	string toString();
	DatalogProgram();
	~DatalogProgram();
};

