#include"Node.h"
Node::Node(){
	data = 0;
	count = 0;
	leftChild = nullptr;
	rightChild = nullptr;
}
Node::~Node(){
	data = 0;
	count = 0;
	leftChild = nullptr;
	rightChild = nullptr;
}
Node::Node(int _data, int _count, Node* _leftChild, Node* _rightChild){
	data = _data;
	count = _count;
	leftChild = _leftChild;
	rightChild = _rightChild;
}
//SETTERS
void Node::setData(const int& _data){
	data = _data;
}
void Node::setCount(const int& _count){
	count = _count;
}
void Node::setLeftChild(Node* _leftChild){
	leftChild = _leftChild;
}
void Node::setRightChild(Node* _rightChild){
	rightChild = _rightChild;
}
//GETTERS
int Node::getData() const{
	return data;
}
int Node::getCount() const{
	return count;
}
Node*& Node::getLeftChild() const{
	Node* temp = leftChild;
	return temp;
}
Node*& Node::getRightChild() const{
	Node* temp = rightChild;
	return temp;
}