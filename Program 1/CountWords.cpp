#include <iostream>
#include <fstream>
#include "WordTree.h"
using namespace std;

int main()
{
	ifstream infile("SampleTextFile.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	WordTree myWordTree;
	for (;;) {
		if (infile.eof()) { break; }
		string currentString;
		
		infile >> currentString; 
		//need to split hyphenated words
		bool isValid = isValidString(currentString);
		if (isValid) {
			myWordTree.add(currentString);
		}

	}

	return 0;
}

bool isValidString(string& inString) {
	bool isValid = true;
	for (int i = 0; i < inString.length; i++) {
		if (isdigit(inString[i])) {
			isValid = false;
			break;
		}
	}
}
