#include "Scheme.h"


Scheme::Scheme()
{
}

Scheme::Scheme(Predicate scheme){
	for (int i = 0; i < scheme.myParams.size(); i++){
		names.push_back(scheme.myParams[i].getName());
	}
}

Scheme::~Scheme()
{
}
