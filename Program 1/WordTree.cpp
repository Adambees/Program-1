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

	}
	else {

	}
}
void WordTree::addHelper(std::string wordToAdd, WordNode* currentNode) {

}

const int WordTree::numWords() const{

}
int WordTree::numWordsHelper(WordNode currentNode) const{

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
;