#pragma once
#include <iostream>
#include "Parser.h"

int main(int argc, char* argv[]){
	ofstream out;
	out.open(argv[2]);
	Parser newParser(argv[1]);
	out << newParser.toString();
	out.close();
} 