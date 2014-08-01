#include "Scheme.h"


Scheme::Scheme()
{
}

Scheme::Scheme(Predicate scheme){
	for (int i = 0; i < scheme.myParams.size(); i++){
		names.push_back(scheme.myParams[i].getName());
	}
}

Scheme::Scheme(Scheme scheme1, Scheme scheme2){
	bool exist = false;
	for (int i = 0; i < scheme1.names.size(); i++){
		names.push_back(scheme1.names[i]);
	}
	for (auto i : scheme2.names){
		names.push_back(i);
	}
}

Scheme::~Scheme()
{
}
