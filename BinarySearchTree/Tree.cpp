#include "Tree.h"
void Tree::DESTROY(Node*& root) {
	if (root == nullptr) {
		return;
	}
	DESTROY(root->leftChild);
	DESTROY(root->rightChild);
	delete root;
}
Tree::Tree() {
	root = nullptr;
}
Tree::~Tree() {
	if (root != nullptr) {
		DESTROY(root);
		root = nullptr;
	}
}