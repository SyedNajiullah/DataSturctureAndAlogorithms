#pragma once
#include"Node.h"
template<class T>
class LinkedList {
protected:
	Node<T>* head;
public:
	LinkedList();
	~LinkedList();
	virtual void insertAtHead(const T& value) = 0;
	virtual void insertAtTail(const T& value) = 0;
	virtual T deleteFromHead() = 0;
	virtual T deleteFromTail() = 0;
	virtual void display() const = 0;
};
template<class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}
template<class T>
LinkedList<T>::~LinkedList() {

}