#pragma once
#include "Predicate.h"
class Scheme
{
public:
	vector<string> names;
	Scheme();
	Scheme(Predicate scheme);
	~Scheme();
};

