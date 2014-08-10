#pragma once
#include <string>
using namespace std;
enum Tokentype
{
	COMMA,
	PERIOD,
	Q_MARK,
	LEFT_PAREN,
	RIGHT_PAREN,
	COLON,
	COLON_DASH,
	SCHEMES,
	FACTS,
	RULES,
	QUERIES,
	ID,
	STRING,
	UNDEFINED,
	NUL
};

string TokenType(Tokentype type);


