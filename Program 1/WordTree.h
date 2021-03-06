#pragma once
#include <string>
#include <iostream>
/*
Class WordTree

*/
class WordTree
{
	friend std::ostream& operator<<(std::ostream&, const WordTree&);
public:
	WordTree();
	~WordTree();
	
	void add(std::string word);
	int numWords() const;
private:
	struct WordNode { 
		std::string word;
		int count;
		WordNode* left;
		WordNode* right;
		WordNode(std::string inWord){
			word = inWord;
			count = 1;
			left = NULL;
			right = NULL;
		}
	};
	WordNode* root;

	void addHelper(std::string, WordNode* currentNode);
	int numWordsHelper(WordNode* currentNode) const;
	void emptyWordTree();
	void emptyWordTreeHelper(WordNode*& currentNode);
	static std::ostream& printHelper(std::ostream&, const WordNode* currentNode);
};

