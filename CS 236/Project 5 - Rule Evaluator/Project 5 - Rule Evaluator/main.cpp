#pragma once
#include <iostream>
#include "Interpretter.h"

int main(int argc, char* argv[]){
	ofstream out;
	out.open(argv[2]);
	Interpretter newInterpreter(argv[1]);
	out << newInterpreter.toString();
	out.close();
} 