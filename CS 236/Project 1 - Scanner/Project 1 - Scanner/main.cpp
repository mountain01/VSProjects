#pragma once
#include <iostream>
#include "Scanner.h"

int main(int argc, char* argv[]){
	ofstream out;
	out.open(argv[2]);
	Scanner newScanner(argv[1]);
	out << newScanner.toString();
	out.close();
} 