#include <iostream>
#include <fstream>
#include "WordTree.h"
using namespace std;

bool isValidString(const string& inString) {
	for (int i = 0; i < int(inString.length()); i++) {
		if (isdigit(inString[i])) {
			return false;
		}
	}
	return true;
}

int main()
{
	ifstream infile("SampleTextDoc.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	WordTree myWordTree;

	for (;;) {
		if (infile.eof()) { break; }
		string currentString;
		
		infile >> currentString; 

		bool isValid = isValidString(currentString);
		
		if (isValid) {
			int wordIterator = 0;
			while (wordIterator < int(currentString.length())) {
				if (currentString[wordIterator] == '-') {
					string firstWord = currentString.substr(0, wordIterator);
					string secondWord = currentString.substr(wordIterator + 1, currentString.length() + 1);
					myWordTree.add(firstWord);
					myWordTree.add(secondWord);
					break;
				}
				else {
					wordIterator++;
				}
			}
			myWordTree.add(currentString);
		}
		
	}
	cout << myWordTree;

	return 1;
}


