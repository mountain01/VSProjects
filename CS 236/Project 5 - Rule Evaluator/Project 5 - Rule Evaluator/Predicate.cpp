#include "Predicate.h"


Predicate::Predicate()
{
}

Predicate::Predicate(string newName){
	name = newName;
}


Predicate::~Predicate()
{
}

string Predicate::toString(){
	string result = name + "(";
	for (int i = 0; i < myParams.size(); i++){
		result += myParams[i].toString()+",";
	}
	result = result.substr(0, result.length() - 1) + ")";
	return result;
}
