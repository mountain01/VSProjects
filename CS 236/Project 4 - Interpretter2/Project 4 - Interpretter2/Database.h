#pragma once
#include "Parser.h"
#include "Relation.h"
#include <map>
using namespace std;

class Database
{
public:
	map<string, Relation> myRelations;
	int ruleIterations;

	Database();
	Database(DatalogProgram dp);
	~Database();

	void makeDB(DatalogProgram dp);
	void addRules(DatalogProgram dp);
	void addRelations(DatalogProgram dp);
	void addTuples(DatalogProgram dp);
	set<pair<int, int>> sameIndex(Relation r1, Relation r2);
	set<Tuple> joinTuples(set<Tuple> r1tup, set<Tuple> r2tup, set<pair<int, int>> myPairs);
	Tuple joinTuple(set<pair<int, int>> pairs, Tuple t1, Tuple t2);
	bool canJoin(set<pair<int, int>> pairs, Tuple t1, Tuple t2);
	vector<int> getProjectIndex(Predicate ruleHead, Relation rel);
	Relation ruleRelation(Predicate pred);
	void insertNewTuples(string name, Relation rel);
	void interpretRule(Rule rule);
	int getSize();
};

