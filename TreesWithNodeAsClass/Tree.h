#pragma once
#include"Node.h"
class Tree{
private:
	void DESTROY(Node*&);
protected:
	Node* root;
public:
	Tree();
	virtual ~Tree();

	virtual void insert(const int& value) = 0;
	virtual void inorderDisplay() const = 0;
	virtual void preorderDisplay() const = 0;
	virtual void postorderDisplay() const = 0;
	virtual bool deleteValue(int value) = 0;
	virtual bool searchValue(const int& value) const = 0;

};