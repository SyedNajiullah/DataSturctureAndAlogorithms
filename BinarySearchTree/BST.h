#pragma once
#include"Tree.h"
template<class T>
class BST : public Tree<T> {
private:
	void INORDER(Node<T>* root) const;
	void PREEORDER(Node<T>* root) const;
	void POSTORDER(Node<T>* root) const;
public:
	BST();
	~BST();

	void insert(const T& value);
	void inOrderDisplay() const;
	void preeOrderDisplay() const;
	void postOrderDisplay() const;
};
template<class T>
void BST<T>::INORDER(Node<T>* root) const{
	if (root != nullptr) {
		INORDER(root->getLeftChild());
		cout << root->getData() << " ";
		INORDER(root->getRightChild());
	}
}
template<class T>
void BST<T>::PREEORDER(Node<T>* root) const{
	if (root != nullptr) {
		cout << root->getData() << " ";
		PREEORDER(root->getLeftChild());
		PREEORDER(root->getRightChild());
	}
}
template<class T>
void BST<T>::POSTORDER(Node<T>* root) const{
	if (root != nullptr) {
		POSTORDER(root->getLeftChild());
		POSTORDER(root->getRightChild());
		cout << root->getData() << " ";
	}
}
template<class T>
BST<T>::BST() : Tree<T>() {

}
template<class T>
BST<T>::~BST() {

}
template<class T>
void BST<T>::insert(const T& value) {
	Node<T>* nn = new Node<T>(value);
	if (Tree<T>::getRoot() == nullptr) {
		Tree<T>::setRoot(nn);
	}
	else {
		Node<T>* temp = Tree<T>::getRoot();
		while (true) {
			if (value < temp->getData()) {
				if (temp->getLeftChild() == nullptr) {
					temp->setLeftChild(nn);
					break;
				}
				else {
					temp = temp->getLeftChild();
				}
			}
			else {
				if (temp->getRightChild() == nullptr) {
					temp->setRightChild(nn);
					break;
				}
				else {
					temp = temp->getRightChild();
				}
			}
		}
	}
}
template<class T>
void BST<T>::inOrderDisplay() const {
	if (Tree<T>::getRoot() == nullptr) {
		cout << "Tree is empty" << endl;
	}
	else {
		INORDER(Tree<T>::getRoot());
	}
}
template<class T>
void BST<T>::preeOrderDisplay() const {
	if (Tree<T>::getRoot() == nullptr) {
		cout << "Tree is empty" << endl;
	}
	else {
		PREEORDER(Tree<T>::getRoot());
	}
}
template<class T>
void BST<T>::postOrderDisplay() const {
	if (Tree<T>::getRoot() == nullptr) {
		cout << "Tree is empty" << endl;
	}
	else {
		POSTORDER(Tree<T>::getRoot());
	}
}