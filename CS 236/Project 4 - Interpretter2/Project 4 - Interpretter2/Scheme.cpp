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
	for (int i = 0; i < scheme2.names.size(); i++){
		exist = false;
		for (int k = 0; k < names.size(); k++){
			if (scheme2.names[i] == names[k]){
				exist = true;
				break;
			}
		}
		if (!exist){
			names.push_back(scheme2.names[i]);
		}
	}
}

Scheme::~Scheme()
{
}
