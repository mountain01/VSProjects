#pragma once
#include <vector>
#include <string>
#include "Predicate.h"
using namespace std;
class Tuple : public vector<string>
{
public:
	Tuple();
	Tuple(Predicate fact);
	~Tuple();
};

