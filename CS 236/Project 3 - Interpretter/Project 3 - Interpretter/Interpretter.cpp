#include "Interpretter.h"
#include <iostream>


Interpretter::Interpretter()
{
}

Interpretter::Interpretter(char* filename){
	Parser newParser(filename);
	newParser.parse();
	myDP = newParser.getDP();
	Database newDB(myDP);
	myDb = newDB;
	result = "";
}


Interpretter::~Interpretter()
{
}

void Interpretter::testQueries(){
	for (int i = 0; i < myDP.queries.size(); i++){
		Relation temp = myDb.myRelations[myDP.queries[i].name];
		for (int k = 0; k < myDP.queries[i].myParams.size(); k++){
			//select
			if (myDP.queries[i].myParams[k].isName()){
				//name
				temp.varInQuery = true;
				//rename variable
				temp.rename(k, myDP.queries[i].myParams[k].getName());

			}
			else{
				//value
				temp.select(k, myDP.queries[i].myParams[k].getValue());
			}
			//project
		}
		result += temp.toString(myDP.queries[i])+"\n";
	}
}

string Interpretter::toString(){
	testQueries();
	return result;
}