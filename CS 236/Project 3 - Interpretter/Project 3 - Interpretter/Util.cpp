#include "Util.h"
#include <sstream>

string itos(int i){
	stringstream ss;
	string answer;
	ss << i;
	ss >> answer;
	return answer;
}