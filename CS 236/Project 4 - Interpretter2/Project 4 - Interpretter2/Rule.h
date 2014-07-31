#pragma once
#include "Predicate.h"
class Rule
{
public:
	Predicate head;
	vector<Predicate> body;

	string toString();

	Rule();
	Rule(Predicate newHead);
	~Rule();
};

