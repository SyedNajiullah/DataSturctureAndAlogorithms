#pragma once
#include "Tree.h"
class BST :public Tree
{
private:// WRAPPER FUNCTIONS
	Node* INSERTNODE(Node* root, const int& value);
	void PREORDERDISPLAY(Node* root) const;
	void INORDERDISPLAY(Node* root) const;
	void POSTORDERDISPLAY(Node* root) const;
	bool SEARCHVALUE(Node* root, const int& value) const;
	void PRINTINORDERSUCCESSORS(Node* root, const int& value) const;
public:
	BST();
	~BST();
	//ALL REQUIRED FUNCTIONS
	void insert(const int& value);
	void preOrderDisplay() const;
	void inOrderDisplay() const;
	void postOrderDisplay() const;
	bool searchValue(const int& value) const;
	void printInorderSuccessors(const int& value) const;
	bool deleteValue(int value);
};