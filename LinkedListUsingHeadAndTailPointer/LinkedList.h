#include"Node.h"
class LinkedList
{
protected:
	Node * head;
	Node * tail;
public:
	LinkedList(); // DEFAULT 
	virtual void insertAtTail(const int& value) = 0;  // TO INSERT AT TAIL
	virtual void insertAtHead(const int & value) = 0; // INSRT AT HEAD
	virtual int deleteFromHead() = 0; // DELETE FROM HEAD
	virtual int deleteFromTail() = 0; // DELETE FROM TAIL
	virtual void display() = 0; // TO DISPLAY LINKED LIST
	virtual bool isEmpty() = 0; // IF HEAD AND TAIL == NULLPTR
	virtual void insertSorted(const int & value) = 0; // TO INSERT IN SORTED FASHION 
	virtual bool deleteValue(const int & value) = 0; // T DELETE VALUE FROM A LINKED LIST
	~LinkedList();
};
LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}
LinkedList::~LinkedList()
{
	delete head;
	head = nullptr;
	delete tail;
	tail = nullptr;
}