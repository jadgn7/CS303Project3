#ifndef TRANSLATOR
#define TRANSLATOR

#include "Morse.h"
#include <fstream>
#include <vector>
#include "map.h"
#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include <map>

using namespace std;

class Translator {
public:
	Translator() {}
	Translator(string input) : fin(input), decode("CENTER") {}
	
	~Translator() {
		fin.close();
	}

	// reads in file translator is initialized with and 
	// constructs a tree to be used with decoding morse code
	void buildTree() {
		string line;
		string letter;
		string code = "";
		string::iterator itr;

		BTNode<string>* current = decode.getRoot();
	
		// load map and vector
		while (fin >> line) {
			current = decode.getRoot();
			itr = line.begin();
			letter = *(itr++); // get letter
			// iterate through morse code
			for (itr; itr != line.end(); itr++) {
				code += *itr;
				if (*itr == '.') { // go left if '.'
					if (current->left == NULL) {
						BTNode<string>* tmp = new BTNode<string>("");
						current->left = tmp;
					}
					current = current->left;
				}
				else if (*itr == '_') { // go right if '_'
					if (current->right == NULL) {
						BTNode<string>* tmp = new BTNode<string>("");
						current->right = tmp;
					}
					current = current->right;
				}
			}
			current->data = letter; // assign node stopped at to current letter
			encode[letter] = code; // put letter, morse pair into map for encoding
		}

		outputTree(decode.getRoot()); // output for debug, remove later
	}

	// outputs tree via infix
	void outputTree(BTNode<string>* n) {
		if (n == NULL) {
			cout << " NULL " << endl;
			return;
		}
		outputTree(n->left);
		cout << " " << n->data << endl;
		outputTree(n->right);
	}


private:
	ifstream fin; // file to construct tree with
	map<string, string> encode;	
	Binary_Tree<string> decode;

};



#endif
