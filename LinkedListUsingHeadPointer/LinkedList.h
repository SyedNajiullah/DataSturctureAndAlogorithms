#include"Node.h"
template<class T>
class LinkedList
{
protected:
	Node<T> * head;
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
	virtual void removeDublicate() = 0;
	virtual int getNumberOFNodes() = 0;
	virtual void insertInBetween(const T& value) = 0;
	virtual void sort() = 0;
	virtual void reverse() = 0;
};
template<class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}
template<class T>
LinkedList<T>::~LinkedList()
{

}