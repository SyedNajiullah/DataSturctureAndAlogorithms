#pragma once
#include "Tree.h"
class BST :public Tree
{
private:
	void INORDERDISPLAY(Node*) const;
	void PREORDERDISPLAY(Node*) const;
	void POSTORDER(Node*) const;
public:
	BST();
	~BST();

	void insert(const int& value);
	void inorderDisplay() const;
	void preorderDisplay() const;
	void postorderDisplay() const;
	bool deleteValue(int value);
	bool searchValue(const int& value) const;
};