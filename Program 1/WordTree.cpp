#include "WordTree.h"
/*
Class WordTree
*/
WordTree::WordTree()
{
	this->root = NULL;
}

WordTree::~WordTree()
{
	this->emptyWordTree();
}

void WordTree::add(std::string wordToAdd) {
	
	if (this->root == NULL) {
		this->root = new WordNode(wordToAdd);
	}
	else {
		addHelper(wordToAdd, this->root);
	}
}
void WordTree::addHelper(std::string wordToAdd, WordNode* currentNode) {
	if (wordToAdd > currentNode->word) {
		if (currentNode->right == NULL) {
			currentNode->right = new WordNode(wordToAdd);
		}
		else {
			addHelper(wordToAdd, currentNode->right);
		}
	}
	else if (wordToAdd < currentNode->word) {
		if (currentNode->left == NULL) {
			currentNode->left = new WordNode(wordToAdd);
		}
		else {
			addHelper(wordToAdd, currentNode->left);
		}
	}
	else {
		currentNode->count++;
	}
}

int WordTree::numWords() const{
	if (this->root == NULL) {
		return 0;
	}
	else {
		return numWordsHelper(this->root);
	}
}
int WordTree::numWordsHelper(WordNode* currentNode) const{
	if (currentNode != NULL) {
		return 1 + numWordsHelper(currentNode->left) + numWordsHelper(currentNode->right);
	}
}

void WordTree::emptyWordTree(){
	if (this->root != NULL) {
		emptyWordTreeHelper(this->root);
	}
}
void WordTree::emptyWordTreeHelper(WordNode*& currentNode) {
	if (currentNode != NULL) {
		emptyWordTreeHelper(currentNode->left);
		emptyWordTreeHelper(currentNode->right);
		delete currentNode;
		currentNode = nullptr;
	}
}
std::ostream& operator<<(std::ostream& output, const WordTree& inTree) {


	return output;
}
;