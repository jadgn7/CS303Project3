#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include "Translator.h"
using namespace std;

int main() {

	Translator t("morse.txt");
	t.buildTree();
	t.encodeLine("Hello");
	
	cin.get();
	return 0;
}
