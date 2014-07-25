#pragma once
#include <iostream>
#include "Database.h"

int main(int argc, char* argv[]){
	ofstream out;
	out.open(argv[2]);
	Database newParser(argv[1]);
	out.close();
} 