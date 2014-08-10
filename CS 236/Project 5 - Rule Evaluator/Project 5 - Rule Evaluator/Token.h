#pragma once
#include "Tokentype.h"
#include <sstream>
#include "Util.h"

using namespace std;

class Token
{
private:
	Tokentype myType;
	string myValue;
	int myLineNumber;
public:
	Token();
	Token(Tokentype type, string value, int lineNumber);
	~Token();

	Tokentype getTokenType();
	int getLineNumber();
	string getValue();

	string toString();
};

