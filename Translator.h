#ifndef TRANSLATOR
#define TRANSLATOR

#include "Morse.h"
#include <fstream>
#include <vector>
#include "map.h"
#include "Binary_Search_Tree.h"

using namespace std;

class Translator {
public:
	typedef pair<Morse, char> TNode;

	Translator() {}
	Translator(string input) : fin(input) {}
	
	~Translator() {
		fin.close();
	}

	void readMorseFile() {
		string line;
		char letter;
		string code = "";
		string::iterator itr;

		// load map and vector
		while (fin >> line) {
			itr = line.begin();
			letter = *(itr++);
			for (itr; itr != line.end(); itr++) {
				code += *itr;
			}
			Morse m(code);
			TNode node;

			encode[letter] = m;
			node.first = m;
			node.second = letter;
			addToVec(nodes, node);
		}

		TNode init;
		init.first = Morse();
		init.second = ' ';
		BTNode<TNode> b(init);
		decode.setRoot(&b);

	}
	// not sure about the best way to go about constructing the tree 
	// or if we should even make a vector for making the tree
	addToVec(vector<TNode>& nodes, TNode node) {
		if (nodes.size() == 0) {
			nodes.push_back(node);
		}

	}

private:
	ifstream fin;
	vector<TNode> nodes;
	KW::Map<char, Morse> encode;
	Binary_Search_Tree<TNode> decode;

};

// not sure if I need to sort
void ShellSort(vector <TNode> &num) {
	int i, temp, flag = 1, numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	TNode key;

	while (true) {    // boolean flag (true when not equal to 0) 
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right

					if (key < num[i]) {
						swapPos = i;
						num[i + gap] = num[i];
						insertionNeeded = true;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;    //Put key into its proper location
				}
			}
		}
	}
	return;
}


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
