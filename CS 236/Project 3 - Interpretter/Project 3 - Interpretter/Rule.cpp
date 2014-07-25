#include "Rule.h"


Rule::Rule()
{
}

Rule::Rule(Predicate newHead){
	head = newHead;
}

string Rule::toString(){
	string result = head.toString() + " :- ";
	for (int i = 0; i < body.size(); i++){
		result += body[i].toString() + ",";
	}
	result = result.substr(0, result.size() - 1);
	return result;
}


Rule::~Rule()
{
}
