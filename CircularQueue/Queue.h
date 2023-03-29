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
	Queue(const Queue & obj);
	Queue & operator=(const Queue & obj);
	~Queue();
	virtual void enQueue(const T obj) = 0;
	virtual T deQueue() = 0;
	virtual bool isFull()const = 0;
	virtual bool isEmpty()const = 0;
	virtual void display()const = 0;
};
template<class T>
Queue<T>::Queue(const Queue & obj)
{
	maxSize = obj.maxSize;
	for (int i = 0; i < obj.maxSize; ++i)
		arr[i] = obj.arr[i];
}
template<class T>
Queue<T> & Queue<T>::operator=(const Queue & obj)
{
	maxSize = obj.maxSize;
	for (int i = 0; i < obj.maxSize; ++i)
		arr[i] = obj.arr[i];
	return *this;
}
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