#include "Stack.h"


Stack::Stack()
{
	arr = nullptr;
	maxSize = 0;
	currentSize = 0;
}

Stack::Stack(const int _maxSize)
{
	maxSize = _maxSize;
	currentSize = 0;
	arr = new char[_maxSize];
}
Stack::Stack(const Stack & obj)
{
	maxSize = obj.maxSize;
	currentSize = obj.currentSize;
	for (int i = 0; i < obj.currentSize; i++)
		arr[i] = obj.arr[i];
}
Stack & Stack ::operator=(const Stack & obj)
{
	maxSize = obj.maxSize;
	currentSize = obj.currentSize;
	for (int i = 0; i < obj.currentSize; i++)
		arr[i] = obj.arr[i];
	return *this;
}

void Stack::push(const char & value)
{
	arr[currentSize++] = value;
}
char Stack::pop()
{
	return arr[--currentSize];
}
char Stack::top() const
{
	return arr[currentSize - 1];
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
	std::cout << "Maximum size is ->" << maxSize << std::endl;
	std::cout << "Current size is ->" << currentSize << std::endl;
	for (int i = 0; i < currentSize; i++)
		std::cout << i << ". " << arr[i] << std::endl;
}

Stack::~Stack()
{
	delete arr;
	arr = nullptr;
	maxSize = 0;
	currentSize = 0;
}
