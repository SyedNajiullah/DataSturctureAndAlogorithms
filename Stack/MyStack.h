#pragma once
#include "Stack.h"
template<class T>
class MyStack :public Stack<T>
{
public:
	MyStack() = default;
	MyStack(int _maxSize);
	MyStack(const MyStack & obj);
	MyStack & operator=(const MyStack & obj);
	~MyStack();

	void push(const T & value);
	T pop();
	void display() const;
	T top() const;
	int getLength() const;

	bool isFull() const;
	bool isEmpty() const;
};
template<class T>
MyStack<T>::MyStack(int _maxSize) :Stack<T>(_maxSize)
{

}
template<class T>
MyStack<T>::MyStack(const MyStack & obj) : Stack<T>(obj)
{

}
template<class T>
MyStack<T> & MyStack<T>::operator=(const MyStack & obj)
{
	Stack<T>::operator=(obj);
	return *this;
}
template<class T>
MyStack<T>::~MyStack()
{

}
template<class T>
int MyStack<T>::getLength() const
{
	return Stack<T>::currentSize;
}
template<class T>
void MyStack<T>::push(const T & value)
{
	if (!isFull())
		Stack<T>::arr[Stack<T>::currentSize++] = value;
	else
		std::cout << "Value Array is already full" << std::endl;
}
template<class T>
T MyStack<T>::pop()
{
	if (!isEmpty())
	{
		Stack<T>::currentSize--;
		return Stack<T>::arr[Stack<T>::currentSize];
	}
	else
	{
		std::cout << "Array is Empty returning 0" << std::endl;
		return 0;
	}
}
template<class T>
void MyStack<T>::display() const
{
	std::cout << "Max size is :" << Stack<T>::maxSize << std::endl;
	std::cout << "Current size is :" << Stack<T>::currentSize << std::endl;
	std::cout << "--ARRAY--" << std::endl;
	for (int i = 0; i < Stack<T>::currentSize; ++i)
		std::cout << i << ". " << Stack<T>::arr[i] << std::endl;
}
template<class T>
T MyStack<T>::top() const
{
	if (!isEmpty())
		return Stack<T>::arr[Stack<T>::currentSize - 1];
	else
	{
		std::cout << "Array is Empty returning 0" << std::endl;
		return 0;
	}
}
template<class T>
bool MyStack<T>::isFull() const
{
	if (Stack<T>::currentSize == Stack<T>::maxSize)
		return true;
	return false;
}
template<class T>
bool MyStack<T>::isEmpty() const
{
	if (Stack<T>::currentSize == 0)
		return true;
	return false;
}