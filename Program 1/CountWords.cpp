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

	for (;;) {
		
		// on windows, new line after last line of data; no line on linux
		if (infile.eof()) { break; }
		
	}

	return 0;
}
