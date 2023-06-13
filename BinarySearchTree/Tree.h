#pragma once
#include"Node.h"
class Tree
{
private:
	void DESTROY(Node*& root);
protected:
	Node* root;
public:
	Tree();
	~Tree();

	virtual void insert(const int& value) = 0;
	virtual void preOrderDisplay() const = 0;
	virtual void inOrderDisplay() const = 0;
	virtual void postOrderDisplay() const = 0;
	virtual bool searchValue(const int& value) const = 0;
	virtual void printInorderSuccessors(const int& value) const = 0;
	virtual bool deleteValue(int value) = 0;

};