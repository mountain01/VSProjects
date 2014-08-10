#include "Scanner.h"
using namespace std;

Scanner::Scanner()
{
	input = "";
	lineNumber = 1;
}

Scanner::Scanner(string fileName){
	input = "";
	ifstream in;
	in.open(fileName, ios::in);
	while (in.good())
	{
		input += in.get();
	}
	in.close();
	lineNumber = 1;
}

Scanner::Scanner(char* filename){
	input = "";
	ifstream in;
	in.open(filename, ios::in);
	while (in.good()){
		input += in.get();
	}
	in.close();
	lineNumber = 1;
}


Scanner::~Scanner()
{
}

string Scanner::getinput(){
	return input;
}

vector<Token> Scanner::getTokens(){
	return myTokens;
}

string Scanner::toString(){
	generateTokens();
	string result = "";
	bool error = false;
	for (int i = 0; i < myTokens.size(); i++){
		if (myTokens[i].getTokenType() == NUL){
			break;
		}
		if (myTokens[i].getTokenType() != UNDEFINED){
			result += myTokens[i].toString();
		}
		else{
			result += "Input Error on line " + itos(myTokens[i].getLineNumber());
			error = true;
		}
	}
	if (!error){
		result += "Total Tokens = " + itos(myTokens.size()-1);
	}
	return result;
}

void Scanner::generateTokens(){
	for (int i = 0; i < input.length(); i++){
		tokenAdded = false;
		badInput = false;
		//SPACES
		while (isspace(input[i]) && input[i] != '\n'){
			i++;
		}
		//end of file
		if (input[i] == EOF){
			break;
		}
		// new line
		if (input[i] == '\n'){
			lineNumber++;
			continue;
		}
		//string
		checkString(i);
		//comma
		checkComma(i);
		//Q_MARK
		checkQMark(i);
		//LEFT_PAREN
		checkParen(i);
		//PERIOD
		checkPeriod(i);
		//COLON
		checkColon(i);
		//COMMENTS
		checkComments(i);
		//ID'S, SCHEMES, FACTS, QUERIES, RULES
		checkID(i);
		if (!tokenAdded)
		{
			Token newToken(UNDEFINED, "", lineNumber);
			myTokens.push_back(newToken);
			break;
		}
		if (badInput){
			break;
		}
	}
	Token newToken(NUL, "", 0);
	myTokens.push_back(newToken);
}

void Scanner::checkQMark(int &i){
	if (input[i] == '?')
	{
		Token newToken(Q_MARK, "?", lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
}

void Scanner::checkID(int& i){
	if (isalpha(input[i]))
	{
		string value = "";
		while (isalpha(input[i]) || isdigit(input[i])){
			value += input[i++];
		}
		i--;
		if (!checkID(value)){
			Token newToken(ID, value, lineNumber);
			myTokens.push_back(newToken);
			tokenAdded = true;
		}
	}
}

void Scanner::checkComments(int& i){
	if (input[i] == '#')
	{
		while (input[i++] != '\n');
		lineNumber++;
		i--;
		tokenAdded = true;
	}
}

void Scanner::checkColon(int& i){
	if (input[i] == ':')
	{
		Tokentype type;
		string value = ":";
		if (input[i + 1] == '-'){
			type = COLON_DASH;
			value += "-";
			i++;
		}
		else
		{
			type = COLON;
		}
		Token newToken(type, value, lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
}

void Scanner::checkPeriod(int& i){
	if (input[i] == '.')
	{
		Token newToken(PERIOD, ".", lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
}

void Scanner::checkParen(int& i){
	if (input[i] == '(')
	{
		Token newToken(LEFT_PAREN, "(", lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
	//RIGHT_PAREN
	else if (input[i] == ')')
	{
		Token newToken(RIGHT_PAREN, ")", lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
}

void Scanner::checkComma(int& i){
	if (input[i] == ',')
	{
		Token newToken(COMMA, ",", lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
}

void Scanner::checkString(int& i){
	if (input[i] == '\'')
	{
		i++;
		string value = "";
		Tokentype type = STRING;
		bool badString = false;
		while (input[i] != '\'')
		{
			if (input[i] == EOF || input[i] == '\n'){
				badString = true;
				type = UNDEFINED;
				value = "";
				break;
			}
			value += input[i++];
		}
		Token newToken(type, value, lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
		if (badString){
			badInput = true;
		}
	}
}

bool Scanner::checkID(string value){
	if (value == "Facts"){
		Token newToken(FACTS, value, lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
	else if (value == "Schemes"){
		Token newToken(SCHEMES, value, lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
	else if (value == "Rules"){
		Token newToken(RULES, value, lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
	else if (value == "Queries"){
		Token newToken(QUERIES, value, lineNumber);
		myTokens.push_back(newToken);
		tokenAdded = true;
	}
	else {
		return false;
	}
	return true;
}