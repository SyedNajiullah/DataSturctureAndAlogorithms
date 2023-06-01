#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node {
private:
	T data;
	Node<T>* leftChild;
	Node<T>* rightChild;
public:
	Node();
	~Node();
	Node(const T& value);

	Node<T>* getLeftChild() const;
	Node<T>* getRightChild() const;
	T getData() const;

	void setLeftChild(Node<T>* value);
	void setRightChild(Node<T>* value);
};
template<class T>
Node<T>::Node() {
	data = T();
	leftChild = nullptr;
	rightChild = nullptr;
}
template<class T>
Node<T>::~Node() {

}
template<class T>
Node<T>::Node(const T& value) {
	data = value;
	leftChild = nullptr;
	rightChild = nullptr;
}
template<class T>
Node<T>* Node<T>::getLeftChild() const {
	return leftChild;
}
template<class T>
Node<T>* Node<T>::getRightChild() const {
	return rightChild;
}
template<class T>
T Node<T>::getData() const {
	return data;
}
template<class T>
void Node<T>::setLeftChild(Node<T>* value) {
	leftChild = value;
}
template<class T>
void Node<T>::setRightChild(Node<T>* value) {
	rightChild = value;
}