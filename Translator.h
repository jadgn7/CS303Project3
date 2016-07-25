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
			code = "";
		}

		//outputTree(decode.getRoot()); // output for debug, remove later
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

	//encodes a string
	string encodeLine(string line){
		string::iterator itr = line.begin();
		string result;
		char currentLetter;
		string currentLetterS;
		//get current letter and add to result
		while(itr != line.end()){
			currentLetter = *itr;
			if (isupper(currentLetter)) { currentLetter = tolower(currentLetter); }//get rid of capitals
			currentLetterS = currentLetter;
			if (currentLetterS==" "){
				result+=" ";
				cout<<"space"<<endl;
			}
			else{
			cout<<currentLetterS<<" "<<encode[currentLetterS]<<endl; //test
			result+= (encode[currentLetterS]+" ");
			}
			itr++;
		}
		cout<<result;//test
		return result;
	}
