#pragma once
#include<iostream>
class Stack
{
private:
	char *arr;
	int maxSize;
	int currentSize;
public:
	Stack();
	Stack(const int _maxSize);
	Stack(const Stack & obj);
	Stack & operator=(const Stack & obj);
	~Stack();

	void push(const char & value);
	char pop();
	char top() const;
	bool isFull() const;
	bool isEmpty() const;
	void display() const;
};

