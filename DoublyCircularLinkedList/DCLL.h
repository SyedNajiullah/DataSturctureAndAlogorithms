#pragma once
#include"LinkedList.h"
template<class T>
class DCLL : public LinkedList<T> {
public:
	DCLL();
	~DCLL();
	void insertAtHead(const T& value);
	void insertAtTail(const T& value);
	T deleteFromHead();
	T deleteFromTail();
	void display() const;
};
template<class T>
DCLL<T>::DCLL() : LinkedList<T>() {

}
template<class T>
DCLL<T>::~DCLL() {
	while (LinkedList<T>::head != nullptr) {
		deleteFromHead();
	}
}
template<class T>
void DCLL<T>::insertAtHead(const T& value) {
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (LinkedList<T>::head == nullptr) {
		LinkedList<T>::head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else {
		newNode->prev = LinkedList<T>::head->prev;
		LinkedList<T>::head->prev->next = newNode;
		newNode->next = LinkedList<T>::head;
		LinkedList<T>::head->prev = newNode;
		LinkedList<T>::head = newNode;
	}
}
template<class T>
void DCLL<T>::insertAtTail(const T& value) {
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (LinkedList<T>::head == nullptr) {
		LinkedList<T>::head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else {
		newNode->next = LinkedList<T>::head;
		LinkedList<T>::head->prev->next = newNode;
		newNode->prev = LinkedList<T>::head->prev;
		LinkedList<T>::head->prev = newNode;
	}
}
template<class T>
T DCLL<T>::deleteFromHead() {
	if (LinkedList<T>::head == nullptr) {
		std::cout << "Linked List is empty" << std::endl;
		return T();
	}
	else if (LinkedList<T>::head->next == LinkedList<T>::head) {
		T value = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		return value;
	}
	else {
		Node<T>* toDelete = LinkedList<T>::head;
		LinkedList<T>::head = LinkedList<T>::head->next;
		T save = LinkedList<T>::head->prev->data;
		LinkedList<T>::head->prev = toDelete->prev;
		toDelete->prev->next = LinkedList<T>::head;
		delete toDelete;
		toDelete = nullptr;
		return save;
	}
}
template<class T>
T DCLL<T>::deleteFromTail() {
	if (LinkedList<T>::head == nullptr) {
		std::cout << "Linked List is empty" << std::endl;
		return T();
	}
	else if (LinkedList<T>::head->next == LinkedList<T>::head) {
		T value = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		return value;
	}
	else {
		Node<T>* toConnect = LinkedList<T>::head->prev->prev;
		T value = LinkedList<T>::head->prev->data;
		delete LinkedList<T>::head->prev;
		toConnect->next = LinkedList<T>::head;
		LinkedList<T>::head->prev = toConnect;
		return value;
	}
}
template<class T>
void DCLL<T>::display() const {
	if (LinkedList<T>::head == nullptr) {
		std::cout << "LL is empty" << std::endl;
	}
	else {
		Node<T>* i = LinkedList<T>::head;
		while (true) {
			std::cout << i->data << " ";
			i = i->next;
			if (i == LinkedList<T>::head) {
				break;
			}
		}
	}
}