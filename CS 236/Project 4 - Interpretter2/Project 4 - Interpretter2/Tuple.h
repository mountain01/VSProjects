#pragma once
#include <vector>
#include <string>
#include "Predicate.h"
#include "Scheme.h"
#include <set>
using namespace std;
class Tuple : public vector<string>
{
public:
	Tuple();
	Tuple(Predicate fact);
	Tuple(Scheme newScheme, set<Tuple> r1Tup, set<Tuple> r2Tup);
	~Tuple();
};

