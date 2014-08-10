#pragma once
#include "Token.h"
#include <vector>
#include <fstream>
using namespace std;

class Scanner
{
private:
	vector<Token> myTokens;
	int lineNumber;
	string input;
	bool tokenAdded;
	bool badInput;

public:
	Scanner();
	Scanner(string fileName);
	Scanner(char* filename);
	~Scanner();
	string getinput();
	void generateTokens();
	vector<Token> getTokens();
	bool checkID(string value);
	string toString();
	void checkColon(int &i);
	void checkString(int& i);
	void checkComma(int& i);
	void checkComments(int& i);
	void checkID(int& i);
	void checkParen(int& i);
	void checkPeriod(int& i);
	void checkQMark(int &i);
};

