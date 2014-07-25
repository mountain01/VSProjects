#pragma once
#include "Predicate.h"
#include "Tuple.h"
#include "Scheme.h"
#include <set>
class Relation
{
public:
	string name;
	set<Tuple> myTuples;
	Scheme myScheme;
	Relation();
	Relation(Predicate scheme);
	~Relation();
	void select();
	void project();
	void rename();
};

