#include "Tuple.h"


Tuple::Tuple()
{
}

Tuple::Tuple(Predicate fact){
	for (int i = 0; i < fact.myParams.size(); i++){
		myVals.push_back(fact.myParams[i].getValue());
	}
}


Tuple::~Tuple()
{
}
