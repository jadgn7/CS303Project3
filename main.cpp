#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
using namespace std;

int main() {
	string test = "._._._";
	string::iterator itr = test.begin();
	
	ifstream fin("morse.txt");
	string line;

	while (fin >> line) {
		cout << line;
	}

	bool t = 'a' < 'b';
	cout << t;

	for (itr; itr != test.end(); itr++) {
		cout << *itr;
	}

	fin.close();
	cin.get();
	return 0;
}