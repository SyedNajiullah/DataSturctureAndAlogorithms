#pragma once
#include<iostream>
class Stack
{
private:
	char * arr;
	int maxSize;
	int currentSize;
public:
	Stack() = default;
	Stack(const int & size);
	Stack(const Stack & obj);
	Stack & operator=(const Stack & obj);
	~Stack();

	void push(const char & var);
	char pop();
	bool isFull() const;
	bool isEmpty() const;
	void display() const;
};