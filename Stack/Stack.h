#pragma once
#include<iostream>
#include<string>
template<class T>
class Stack
{
protected:
	T * arr;
	int currentSize;
	int maxSize;
public:
	Stack() = default;
	Stack(int _maxSize);
	Stack(const Stack & obj);
	Stack & operator=(const Stack & obj);
	~Stack();

	virtual void push(const T & value) = 0;
	virtual T pop() = 0;
	virtual void display() const = 0;
	virtual T top() const = 0;
	virtual int getLength() const = 0;

	virtual bool isFull() const = 0;
	virtual bool isEmpty() const = 0;
};
template<class T>
Stack<T>::Stack(int _maxSize)
{
	currentSize = 0;
	maxSize = _maxSize;
	arr = new T[maxSize];
}
template<class T>
Stack<T>::Stack(const Stack & obj)
{
	currrentSize = obj.currrentSize;
	maxSize = obj.maxSize;
	arr = new T[obj.maxSize];
	for (int i = 0; i < currrentSize; ++i)
		arr[i] = obj.arr[i];
}
template<class T>
Stack<T>  & Stack<T>::operator=(const Stack & obj)
{
	currrentSize = obj.currrentSize;
	maxSize = obj.maxSize;
	arr = new T[obj.maxSize];
	for (int i = 0; i < currrentSize; ++i)
		arr[i] = obj.arr[i];
	return *this;
}
template<class T>
Stack<T>::~Stack()
{
	delete[]arr;
	arr = nullptr;
	currentSize = 0;
	maxSize = 0;
}
