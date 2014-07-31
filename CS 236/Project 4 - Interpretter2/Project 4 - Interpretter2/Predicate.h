#pragma once
#include "Parameter.h"
#include <vector>

class Predicate
{
public:
	string name;
	vector<Parameter> myParams;

	string toString();

	Predicate();
	Predicate(string newName);
	~Predicate();
};

