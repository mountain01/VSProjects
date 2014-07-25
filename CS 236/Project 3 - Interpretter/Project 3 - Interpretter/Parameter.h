#pragma once
#include <string>
using namespace std;

class Parameter
{
private:
	string name;
	string value;
	bool hasName;
	bool hasValue;
public:
	Parameter();
	Parameter(string value, bool isName);
	~Parameter();

	string toString();

	void setName(string newName);
	void setValue(string newValue);
	string getName();
	string getValue();

};

