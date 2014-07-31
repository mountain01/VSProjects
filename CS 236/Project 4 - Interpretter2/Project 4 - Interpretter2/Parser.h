#pragma once
#include "Scanner.h"
#include "DatalogProgram.h"
class Parser
{
private:
	vector<Token> myTokens;
	Token curToken;
	DatalogProgram dp;
	Predicate pred;
	vector<Predicate> predList;
	Parameter param;
	Rule rul;
	bool toStringFlag;

public:
	int tokenIndex;
	Parser();
	Parser(string fileName);
	Parser(char* filename);
	~Parser();

	DatalogProgram getDP();
	void parse();
	string toString();
	void datalogProgram();
	void schemeList();
	void scheme();
	void factList();
	void fact();
	void ruleList();
	void rule();
	void queryList();
	void query();
	void predicateList();
	void predicate();
	void parameterList();
	void parameter();
	vector<Token> getTokens();
	void match(Tokentype token);
	void error();
};

