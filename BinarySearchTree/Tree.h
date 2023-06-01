#pragma once
#include"Node.h"
template<class T>
class Tree {
private:
	Node<T>* root;
	void DELETEALLNODES(const Node<T>* root);
public:
	Tree();
	~Tree();

	virtual void insert(const T& value) = 0;
	virtual void inOrderDisplay() const = 0;
	virtual void preeOrderDisplay() const = 0;
	virtual void postOrderDisplay() const = 0;

	Node<T>* getRoot() const;
	void setRoot(Node<T>* value);
};
template<class T>
void Tree<T>::DELETEALLNODES(const Node<T>* root) {
	if (root != nullptr) {
		DELETEALLNODES(root->getLeftChild());
		DELETEALLNODES(root->getRightChild());
		delete root;
	}
}
template<class T>
Tree<T>::Tree() {
	root = nullptr;
}
template<class T>
Tree<T>::~Tree() {
	if (root != nullptr) {
		DELETEALLNODES(root);
	}
	root = nullptr;
}
template<class T>
Node<T>* Tree<T>::getRoot() const {
	return root;
}
template<class T>
void Tree<T>::setRoot(Node<T>* value) {
	root = value;
}