#include "Tuple.h"


Tuple::Tuple()
{
}

Tuple::Tuple(Predicate fact){
	for (int i = 0; i < fact.myParams.size(); i++){
		push_back(fact.myParams[i].getValue());
	}
}

Tuple::Tuple(Scheme newScheme, set<Tuple> r1Tup, set<Tuple> r2Tup){

}


Tuple::~Tuple()
{
}
