#pragma once
#include<iostream>
using namespace std;
class Node{
private:
	int data;
	int count;
	Node* leftChild;
	Node* rightChild;
public:
	Node();
	~Node();
	Node(int _data, int _count, Node* _leftChild, Node* _rightChild);
	//SETTERS
	void setData(const int& _data);
	void setCount(const int& _count);
	void setLeftChild(Node* _leftChild);
	void setRightChild(Node* _rightChild);
	//GETTERS
	int getData() const;
	int getCount() const;
	Node*& getLeftChild() const;
	Node*& getRightChild() const;
};