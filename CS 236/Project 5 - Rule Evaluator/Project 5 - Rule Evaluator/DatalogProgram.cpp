#include "DatalogProgram.h"
#include "Util.h"


DatalogProgram::DatalogProgram()
{
}


DatalogProgram::~DatalogProgram()
{
}

string DatalogProgram::toString(){
	int i;
	string result = "Success!\n";
	string schemesString = "Schemes("+itos(schemes.size())+"):\n";
	for (i = 0; i < schemes.size(); i++){
		schemesString += "  " + schemes[i].toString() + "\n";
	}
	string factsString = "Facts(" + itos(facts.size()) + "):\n";
	for (i = 0; i < facts.size(); i++){
		factsString += "  " + facts[i].toString() + "\n";
	}
	string ruleString = "Rules(" + itos(rules.size()) + "):\n";
	for (i = 0; i < rules.size(); i++){
		ruleString += "  " + rules[i].toString() + "\n";
	}
	string queryString = "Queries(" + itos(queries.size()) + "):\n";
	for (i = 0; i < queries.size(); i++){
		queryString += "  " + queries[i].toString() + "\n";
	}
	string domainString = "Domain(" + itos(domain.size()) + "):\n";
	for (set<string>::iterator it = domain.begin(); it != domain.end();++it){
		domainString += "  '" + *it + "'\n";
	}


	return result + schemesString + factsString + ruleString + queryString + domainString;
}
