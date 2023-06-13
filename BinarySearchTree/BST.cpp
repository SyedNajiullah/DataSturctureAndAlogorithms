#include "BST.h"
Node* BST::INSERTNODE(Node* root, const int& value) {
	if (root == nullptr) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
		return newNode;
	}
	else if (value < root->data) {
		root->leftChild = INSERTNODE(root->leftChild, value);
	}
	else if (value >= root->data) {
		root->rightChild = INSERTNODE(root->rightChild, value);
	}
	return root;
}
bool BST::SEARCHVALUE(Node* root, const int& value) const{
	if (root == nullptr) {
		return false;
	}
	else if (root->data == value) {
		return true;
	}
	else if (value < root->data) {
		return (SEARCHVALUE(root->leftChild, value));
	}
	else if (value >= root->data) {
		return (SEARCHVALUE(root->rightChild, value));
	}
}
void BST::PRINTINORDERSUCCESSORS(Node* root, const int& value) const {
	if (root == nullptr) {
		return;
	}
	PRINTINORDERSUCCESSORS(root->leftChild, value);
	if (root->data > value)
	{
		std::cout << root->data << " ";
	}
	PRINTINORDERSUCCESSORS(root->rightChild, value);
}
void BST::PREORDERDISPLAY(Node* root) const {
	if (root == nullptr) {
		return;
	}
	std::cout << root->data << " ";
	PREORDERDISPLAY(root->leftChild);
	PREORDERDISPLAY(root->rightChild);
}
void BST::INORDERDISPLAY(Node* root) const{
	if (root == nullptr){
		return;
	}
	INORDERDISPLAY(root->leftChild);
	std::cout << root->data << " ";
	INORDERDISPLAY(root->rightChild);
}
void BST::POSTORDERDISPLAY(Node* root) const{
	if (root == nullptr){
		return;
	}
	POSTORDERDISPLAY(root->leftChild);
	POSTORDERDISPLAY(root->rightChild);
	std::cout << root->data << " ";
}
BST::BST(): Tree() {

}
BST::~BST() {

}
void BST::insert(const int& value) {
	if (root == nullptr) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;

		root = newNode;
	}
	else {
		root = INSERTNODE(root, value);
	}
}
void BST::preOrderDisplay() const {
	if (root == nullptr) {
		std::cout << "Tree is empty" << std::endl;
	}
	else {
		PREORDERDISPLAY(root);
	}
}
void BST::inOrderDisplay() const{
	if (root == nullptr){
		std::cout << "Tree is empty" << std::endl;
	}
	else{
		INORDERDISPLAY(root);
	}
}
void BST::postOrderDisplay() const{
	if (root == nullptr){
		std::cout << "Tree is empty" << std::endl;
	}
	else{
		POSTORDERDISPLAY(root);
	}
}
bool BST::searchValue(const int& value) const {
	if (root == nullptr) {
		return false;
	}
	else {
		return SEARCHVALUE(root, value);
	}
}
void BST::printInorderSuccessors(const int& value) const {
	if (root == nullptr) {
		std::cout << "There are no successor " << std::endl;
	}
	else if (searchValue(value) == false) {
		std::cout << "value is not present in Tree" << std::endl;
	}
	else {
		PRINTINORDERSUCCESSORS(root, value);
	}
}

bool BST::deleteValue(int value) {
	if (root == nullptr) { // EMPTY TREE
		std::cout << "Tree is empty" << std::endl;
		return false;
	}
	else if (root->leftChild == nullptr && root->rightChild == nullptr) { // ONLY ROOT CHILD EXITS
		if (value == root->data) {
			delete root;
			root = nullptr;
			return true;
		}
		else {
			return false;
		}
	}
	else if (root->leftChild != nullptr && root->rightChild == nullptr && value == root->data) { //ROOT HAS NO LEFT CHILD AND VALUE == ROOT->DATA
		Node* del = root;
		root = root->leftChild;
		delete del;
		del = nullptr;
		return true;
	}	 
	else if (root->leftChild == nullptr && root->rightChild != nullptr && value == root->data){ // //NO RIGHT CHILD VALUE == ROOT->DATA
		Node* del = root;
		root = root->rightChild;
		delete del;
		del = nullptr;
		return true;
	}
	else //REST OF THE CASES EXCEPT ROOT
	{
		Node* parent = root;
		Node* toDelete = root;
		while (toDelete->data != value) { // FINDING NODE TO BE DELETED
			if (value < toDelete->data) {
				parent = toDelete;
				toDelete = toDelete->leftChild;
			}
			else if (value >= toDelete->data) {
				parent = toDelete;
				toDelete = toDelete->rightChild;
			}
			else if (toDelete == nullptr) {
				return false;
			}
		}
		if (toDelete->leftChild != nullptr && toDelete->rightChild != nullptr) { // BOTH CHILDREN CASES
			Node* del = toDelete;
			parent = toDelete;

			toDelete = toDelete->rightChild;

			if (toDelete->leftChild != nullptr) {
				while (toDelete->leftChild != nullptr) {
					parent = toDelete;
					toDelete = toDelete->leftChild;
				}
			}

			del->data = toDelete->data;
			value = toDelete->data;
		}
		if (toDelete->leftChild == nullptr && toDelete->rightChild == nullptr) { // NO CHILD CASE
			if (value < parent->data) {
				delete toDelete;
				toDelete = nullptr;
				parent->leftChild = nullptr;
				return true;
			}
			else if (value >= parent->data) {
				delete toDelete;
				toDelete = nullptr;
				parent->rightChild = nullptr;
				return true;
			}
		}
		if (toDelete->leftChild == nullptr && toDelete->rightChild != nullptr) {
			if (value < parent->data) {
				parent->leftChild = toDelete->rightChild;
				delete toDelete;
				toDelete = nullptr;
				return true;
			}
			else if (value >= parent->data) {
				parent->rightChild = toDelete->rightChild;
				delete toDelete;
				toDelete = nullptr;
				return true;
			}
		}
		if (toDelete->leftChild != nullptr && toDelete->rightChild == nullptr) {
			if (value < parent->data) {
				parent->leftChild = toDelete->leftChild;
				delete toDelete;
				toDelete = nullptr;
				return true;
			}
			else if (value >= parent->data) {
				parent->rightChild = toDelete->leftChild;
				delete toDelete;
				toDelete = nullptr;
				return true;
			}
		}
	}
}