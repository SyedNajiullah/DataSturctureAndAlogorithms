#pragma once
#include"Queue.h"

template<class T>
class myQueue :public Queue<T>
{
private:
	int startingPoint;   //Starting point of arr
	int endingPoint;    //Ending point of arr
public:
	myQueue() = default;  // Dafault constructor
	~myQueue();  // Destuctor
	myQueue(const myQueue & obj);  // copy constructor 
	myQueue & operator=(const myQueue & obj); // operator =
	myQueue(const int _maxSize);  // parameterize connstructor
	void enQueue(const T obj);  // To add value 
	T deQueue(); // To aff value
	bool isFull()const;  // To check if arr is full or not
	bool isEmpty()const;  // To check if arr in empty or not
	void display()const; // To display elements of array
};
template<class T>
myQueue<T>::myQueue(const myQueue & obj) :Queue<T>(obj)
{
	startingPoint = obj.startingPoint;
	endingPoint; = obj.endingPoint;
}
template<class T>
myQueue<T> & myQueue<T>::operator=(const myQueue & obj)
{
	startingPoint = obj.startingPoint;
	endingPoint = obj.endingPoint;
	Queue::operator=(obj);
	return *this;
}
template<class T>
myQueue<T>::~myQueue() // 0(1) = Time complexity
{
	startingPoint = 0;
	endingPoint = 0;
}
template<class T>
myQueue<T>::myQueue(const int _maxSize) :Queue<T>(_maxSize) // 0(1)
{
	startingPoint = 0;
	endingPoint = 0;
}
template<class T>
void myQueue<T>::enQueue(const T obj) // 0(1)
{
	if (!isFull())
	{
		Queue<T>::arr[endingPoint % Queue<T>::maxSize] = obj;
		endingPoint++;
	}
	else
		std::cout << "Queue is already FULL" << std::endl;
}
template<class T>
T myQueue<T>::deQueue() // 0(1)
{
	if (isEmpty())
	{
		std::cout << "Queue is already empty returning 0" << std::endl;
		return 0;
	}
	else
	{
		T save =  Queue<T>::arr[startingPoint % Queue<T>::maxSize];
		startingPoint++;
		return save;
	}
}
template<class T>
bool myQueue<T>::isFull() const // 0(1)
{
	if (startingPoint - endingPoint == Queue<T>::maxSize)
		return true;
	return false;
}
template<class T>
bool myQueue<T>::isEmpty() const // 0(1)
{
	if (startingPoint - endingPoint == 0)
		return true;
	return false;
}
template<class T>
void myQueue<T>::display() const
{
	std::cout << "Starting point is ->" << startingPoint << std::endl;
	std::cout << "Ending point is ->" << endingPoint << std::endl;
	for (int i = startingPoint; i < endingPoint; ++i)
	{
		std::cout << i % Queue<T>::maxSize << ". " << Queue<T>::arr[i % Queue<T>::maxSize] << std::endl;
	}
	std::cout << std::endl;
}