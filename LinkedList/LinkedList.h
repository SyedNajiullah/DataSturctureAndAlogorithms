#include"Node.h"
template<class T>
class LinkedList
{
protected:
	Node<T> * head;
	Node<T> * tail;
public:
	LinkedList();
	~LinkedList();

	virtual void insertAtTail(const T& value) = 0;
	virtual void insertAtHead(const T& value) = 0;
	virtual T deleteFromTail() = 0;
	virtual T deleteFromHead() = 0;
	virtual void display() = 0;
	virtual void insertSorted(const T& value) = 0;
	virtual bool deleteValue(const T&value) = 0;
	virtual bool isEmpty()const = 0;
};
template<class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}
template<class T>
LinkedList<T>::~LinkedList()
{
	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		delete head;
		head = nullptr;
		delete tail;
		tail = nullptr;
	}
}