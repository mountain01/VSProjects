#include "Parameter.h"


Parameter::Parameter()
{
}


Parameter::~Parameter()
{
}

string Parameter::toString(){
	if (hasName){
		return name;
	}
	else{
		return "'" + value + "'";
	}
}


Parameter::Parameter(string newValue, bool isName){
	if (isName){
		name = newValue;
		value = "";
		hasName = true;
		hasValue = false;
	}
	else{
		value = newValue;
		name = "";
		hasValue = true;
		hasName = false;
	}
}

void Parameter::setName(string newName){
	if (hasName){
		name = newName;
	}
}

void Parameter::setValue(string newValue){
	if (hasValue){
		value = newValue;
	}
}

string Parameter::getName(){
	if (hasName){
		return name;
	}
}

string Parameter::getValue(){
	if (hasValue){
		return value;
	}
}

bool Parameter::isName(){
	return hasName;
}
