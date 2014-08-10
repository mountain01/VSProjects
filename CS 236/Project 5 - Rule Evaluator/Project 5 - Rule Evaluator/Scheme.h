#pragma once
#include "Predicate.h"
class Scheme
{
public:
	vector<string> names;
	Scheme();
	Scheme(Predicate scheme);
	Scheme(Scheme scheme1, Scheme scheme2);
	~Scheme();
};

