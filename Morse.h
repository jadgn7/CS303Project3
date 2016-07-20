#ifndef MORSE
#define MORSE

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

struct Morse{
	Morse(){}

	Morse(const string& seq) {
		code = seq;
		id = idGen(seq);
	}
	
	// generates ids used for comparison
	int idGen(string seq) {
		int result = 0;
		int exponent = 4;
		string::iterator itr = seq.begin();

		for (itr; itr != seq.end(); itr++) {
			char in = *itr;
			switch (in) {
			case '.':
				result += -1 * 10 ^ exponent;
				break;
			case '_':
				result += +1 * 10 ^ exponent;
				break;
			default:
				throw exception("Invalid input must be '.' or '_'");
			}
			exponent--;
		}
	}

	// Overloaded Comparison Operators
	bool operator>(Morse m) {
		return id > m.id;
	}
	bool operator<(Morse m) {
		return id < m.id;
	}
	bool operator==(Morse m) {
		return id == m.id;
	}

	int id;
	string code;
};

typedef pair<Morse, char> TNode;

bool operator<(TNode lhs, TNode rhs) {
	return lhs.first < rhs.first;
}
bool operator>(TNode lhs, TNode rhs) {
	return lhs.first > rhs.first;
}
bool operator==(TNode lhs, TNode rhs) {
	return lhs.first == rhs.first;
}
#endif
