#include "Parser.h"
#include <iostream>


Parser::Parser()
{

}

Parser::Parser(string fileName){
	Scanner newScanner(fileName);
	tokenIndex = 0;
	newScanner.generateTokens();
	myTokens = newScanner.getTokens();
	curToken = myTokens[tokenIndex++];
	toStringFlag = false;
}

Parser::Parser(char* filename){
	Scanner newScanner(filename);
	tokenIndex = 0;
	newScanner.generateTokens();
	myTokens = newScanner.getTokens();
	curToken = myTokens[tokenIndex++];
	toStringFlag = false;
}
Parser::~Parser()
{
}

void Parser::parse(){
	try {
		datalogProgram();
	}
	catch (string e){
		string errorString = e + curToken.toString();
		if (toStringFlag){
			throw errorString;
		}
		cout << errorString;
	}
}

string Parser::toString(){
	try{
		toStringFlag = true;
		parse();
		return dp.toString();
	}
	catch (string e){
		return e;
	}
}

void Parser::datalogProgram(){
	if (curToken.getTokenType() == SCHEMES){
		match(SCHEMES);
		match(COLON);
		schemeList();
		match(FACTS);
		match(COLON);
		factList();
		match(RULES);
		match(COLON);
		ruleList();
		match(QUERIES);
		match(COLON);
		queryList();
		match(NUL);
	}
	else{
		error();
	}
}

void Parser::schemeList(){
	scheme();
	dp.schemes.push_back(pred);
	if (curToken.getTokenType() == ID){
		schemeList();
	}
}

void Parser::scheme(){
	predicate();
}

void Parser::factList(){
	if (curToken.getTokenType() == ID){
		fact();
		dp.facts.push_back(pred);
		if (curToken.getTokenType() == ID){
			factList();
		}
	}
}

void Parser::fact(){
	predicate();
	match(PERIOD);
}

void Parser::ruleList(){
	if (curToken.getTokenType() == ID){
		rule();
		dp.rules.push_back(rul);
		if (curToken.getTokenType() == ID){
			ruleList();
		}
	}
}

void Parser::rule(){
	predicate();
	Rule newRul(pred);
	rul = newRul;
	match(COLON_DASH);
	predicateList();
	rul.body = predList;
	predList.clear();
	match(PERIOD);
}

void Parser::queryList(){
	query();
	dp.queries.push_back(pred);
	if (curToken.getTokenType() == ID){
		queryList();
	}
}

void Parser::query(){
	predicate();
	match(Q_MARK);
}

void Parser::predicateList(){
	predicate();
	predList.push_back(pred);
	if (curToken.getTokenType() == COMMA){
		match(COMMA);
		predicateList();
	}
}

void Parser::predicate(){
	Predicate newPred(curToken.getValue());
	pred = newPred;
	match(ID);
	match(LEFT_PAREN);
	parameterList();
	match(RIGHT_PAREN);
}

void Parser::parameterList(){
	parameter();
	pred.myParams.push_back(param);
	if (curToken.getTokenType() == COMMA){
		match(COMMA);
		parameterList();
	}
}

void Parser::parameter(){
	if (curToken.getTokenType() == ID){
		Parameter newParam(curToken.getValue(), true);
		param = newParam;
		match(ID);
	}
	else if (curToken.getTokenType() == STRING)
	{
		Parameter newParam(curToken.getValue(), false);
		param = newParam;
		dp.domain.insert(curToken.getValue());
		match(STRING);
	}
	else
	{
		error();
	}
}

vector<Token> Parser::getTokens(){
	return myTokens;
}

void Parser::match(Tokentype tokentype){
	if (curToken.getTokenType() == tokentype){
		if (tokenIndex < myTokens.size()){
			curToken = myTokens[tokenIndex++];
		}
	}
	else {
		error();
	}
}

void Parser::error(){
	string errorMessage = "Failure!\n  ";
	throw errorMessage;
}
