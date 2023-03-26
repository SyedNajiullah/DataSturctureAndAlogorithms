#include "Stack.h"

Stack::Stack(const int & size)
{
	maxSize = size;
	currentSize = 0;
	arr = new char[maxSize];
}

Stack::Stack(const Stack & obj)
{
	maxSize = obj.maxSize;
	currentSize = obj.currentSize;
	for (int i = 0; i < obj.currentSize; i++)
	{
		arr[i] = obj.arr[i];
	}
}
Stack & Stack ::operator=(const Stack & obj)
{
	maxSize = obj.maxSize;
	currentSize = obj.currentSize;
	for (int i = 0; i < obj.currentSize; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

void Stack::push(const char & var)
{
	if (isFull() == false)
		arr[currentSize++] = var;
	else
		std::cout << "Array is full cannot add a new member" << std::endl;
}
char Stack::pop()
{
	if (isEmpty())
	{
		std::cout << "Cannot remove a element" << std::endl;
		std::cout << "Returning first index" << std::endl;
		return arr[0];
	}
	else
	{
		return arr[--currentSize];
	}
}
bool Stack::isFull() const
{
	if (currentSize == maxSize)
		return true;
	return false;
}
bool Stack::isEmpty() const
{
	if (currentSize == 0)
		return true;
	return false;
}
void Stack::display() const
{
	for (int i = 0; i < currentSize; i++)
		std::cout << i << ". " << arr[i] << std::endl;

	std::cout << "Maximum size is ->" << maxSize << std::endl;
	std::cout << "Current size is ->" << currentSize << std::endl;
}

Stack::~Stack()
{
	delete[]arr;
	arr = nullptr;
	currentSize = 0;
	maxSize = 0;
}
