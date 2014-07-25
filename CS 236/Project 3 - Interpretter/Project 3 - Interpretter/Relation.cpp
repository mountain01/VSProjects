#include "Relation.h"


Relation::Relation()
{
}

Relation::Relation(Predicate scheme){
	Scheme newScheme(scheme);
	myScheme = newScheme;
	name = scheme.name;
}

Relation::~Relation()
{
}
