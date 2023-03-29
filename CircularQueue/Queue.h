#pragma once
#include<iostream>
template<class T>
class Queue
{
protected:
	T * arr;
	int maxSize;
public:
	Queue() = default;
	Queue(const int _maxSize);
	~Queue();
	virtual void enQueue(const T obj) = 0;
	virtual T deQueue() = 0;
	virtual bool isFull()const = 0;
	virtual bool isEmpty()const = 0;
	virtual void display()const = 0;
};
template<class T>
Queue<T>::Queue(int _maxSize)
{
	maxSize = _maxSize;
	arr = new T[_maxSize];
}
template<class T>
Queue<T>::~Queue()
{
	delete[]arr;
	arr = nullptr;
	maxSize = 0;
}