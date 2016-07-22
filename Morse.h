#ifndef MORSE
#define MORSE

#include <string>

using namespace std;

// Don't think we will need this but just in case
struct Morse{
	Morse(){
		code = "";
	}

	Morse(const string& seq) {
		code = seq;
	}

	string code;
};


#endif
