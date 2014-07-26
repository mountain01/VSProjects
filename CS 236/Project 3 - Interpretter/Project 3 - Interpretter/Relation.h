#pragma once
#include "Predicate.h"
#include "Tuple.h"
#include "Scheme.h"
#include "Util.h"
#include <set>
class Relation
{
public:
	bool varInQuery;
	string name;
	set<Tuple> myTuples;
	Scheme myScheme;
	Relation();
	Relation(Predicate scheme);
	~Relation();
	void select(int index, string value);
	void select(int index1, int index2);
	void project();
	void rename(int index, string newCol);
	string toString(Predicate query);
};

