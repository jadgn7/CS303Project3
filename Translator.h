#ifndef TRANSLATOR
#define TRANSLATOR

#include "Morse.h"
#include <fstream>
#include "map.h"
#include "Binary_Search_Tree.h"

using namespace std;

class Translator {
public:
	typedef pair<Morse, char> TNode;

	Translator(string input) : fin(input) {}
	
	~Translator() {
		fin.close();
	}

	void readMorseFile() {
		string line;
		char letter;
		string code = "";
		string::iterator itr;

		while (fin >> line) {
			itr = line.begin();
			letter = *(itr++);
			for (itr; itr != line.end(); itr++) {
				code += *itr;
			}
			Morse m(code);
			encode[letter] = m;
		}
	}

private:
	ifstream fin;
	KW::Map<char, Morse> encode;
	Binary_Search_Tree<TNode> decode;

};




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
