#pragma once
#include <vector>
#include <string>
#include "Predicate.h"
using namespace std;
class Tuple : public vector<string>
{
public:
	vector<string> myVals;
	Tuple();
	Tuple(Predicate fact);
	~Tuple();
};

