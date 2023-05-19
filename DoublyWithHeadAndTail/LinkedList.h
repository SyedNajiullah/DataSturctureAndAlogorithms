#pragma once
#include"Node.h"
template<class T>
class LinkedList
{
protected:
	Node<T> *head;
	Node<T> *tail;
public:
	LinkedList();
	~LinkedList();
	virtual void insertAtHead(const T& value) = 0;
	virtual void insertAtTail(const T& value) = 0;
	virtual T deleteFromHead() = 0;
	virtual T deleteFromTail() = 0;
	virtual void displayFromHead() = 0;
	virtual void displayFromTail() = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isSingle() const = 0;
	virtual void insertSorted(const T& value) = 0;
	virtual bool deleteValue(const T& value) = 0;
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

}