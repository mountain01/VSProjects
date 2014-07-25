#include "Tokentype.h"


string TokenType(Tokentype type){
	string result;
	switch (type)
	{
	case COMMA:
		result = "COMMA"; break;
	case PERIOD:
		result = "PERIOD"; break;
	case Q_MARK:
		result = "Q_MARK"; break;
	case LEFT_PAREN:
		result = "LEFT_PAREN"; break;
	case RIGHT_PAREN:
		result = "RIGHT_PAREN"; break;
	case COLON:
		result = "COLON"; break;
	case COLON_DASH:
		result = "COLON_DASH"; break;
	case SCHEMES:
		result = "SCHEMES"; break;
	case FACTS:
		result = "FACTS"; break;
	case RULES:
		result = "RULES"; break;
	case QUERIES:
		result = "QUERIES"; break;
	case ID:
		result = "ID"; break;
	case STRING:
		result = "STRING"; break;
	case UNDEFINED:
		result = "UNDEFINED"; break;
	case NUL:
		result = "EOF"; break;
	default:
		break;
	}
	return result;
}