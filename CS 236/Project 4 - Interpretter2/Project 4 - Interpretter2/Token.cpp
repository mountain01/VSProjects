#include "Token.h"


Token::Token()
{
	myType = NUL;
	myValue = "";
	myLineNumber = 0;
}

Token::Token(Tokentype type, string value, int lineNumber){
	myType = type;
	myValue = value;
	myLineNumber = lineNumber;
}

Tokentype Token::getTokenType(){
	return myType;
}

int Token::getLineNumber(){
	return myLineNumber;
}

string Token::getValue(){
	return myValue;
}


Token::~Token()
{
}

string Token::toString(){

	string returnString = "(";
	returnString += TokenType(myType) + ",\"";
	returnString += myValue + "\",";
	returnString += itos(myLineNumber) + ")\n";
	return returnString;


}
