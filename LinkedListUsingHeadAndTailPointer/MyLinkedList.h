#include"LinkedList.h"
class MyLinkedList : public LinkedList
{
private:
	void insertAtTail(const int& value);
	void insertAtHead(const int & value);
public:
	MyLinkedList();
	~MyLinkedList();
	int deleteFromHead();
	int deleteFromTail();
	void display();
	bool isEmpty();
	void insertSorted(const int & value);
	bool deleteValue(const int & value);
};
MyLinkedList::MyLinkedList()
{

}
MyLinkedList::~MyLinkedList()
{

}
void MyLinkedList::insertSorted(const int & value)
{
	if (isEmpty())  // IF HEAD AND TAIL == NULLPTR
	{
		insertAtHead(value); // or insert at tail means the same
	}
	else if (head == tail) // single node case
	{
		if (value > head->data)
		{
			insertAtTail(value);
		}
		if (value <= head->data)
		{
			insertAtHead(value);
		}
	}
	else if (value <= head->data) // IF VALUE < HEAD'S DATA
	{
		insertAtHead(value);
	}
	else if (value >= tail->data) // IF VALUE > HEAD'S DATA
	{
		insertAtTail(value);
	}
	else // TO INSERT IN BETWEEN THE LINKED LIST
	{
		Node * temp = head;
		while (true)
		{
			if (value >= temp->data && value <= temp->next->data)
			{
				Node * temp1 = new Node[1];
				temp1->data = value;
				temp1->next = nullptr;
				temp1->next = temp->next;
				temp->next = temp1;
				break;
			}
			else
			{
				temp = temp->next;  // TO MOVE TO NEXT INDEX
			}
		}
	}
}
bool MyLinkedList::deleteValue(const int & value) // DELETE VALUE GIVEN BY USER
{
	if (isEmpty())
	{
		std::cout << "Cannot delete value" << std::endl;
		return false;
	}
	else if (head == tail && value == head->data)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else if (head == tail && value != head->data)
	{
		return false;
	}
	else if (value == head->data) //head data deletion
	{
		deleteFromHead();
		return true;
	}
	else if (value == tail->data) //tail data deletion
	{
		deleteFromTail();
		return true;
	}
	else
	{
		Node * temp = head;
		while (true)
		{
			if (temp->next == nullptr)  // VALUE NOT FOUND
			{
				std::cout << "Value not found in linked list" << std::endl;
				return false;
			}
			else if (value == temp->next->data)
			{
				Node * temp1 = temp->next;
				temp->next = temp->next->next;
				delete temp1;
				temp1 = nullptr;
				return true;
			}
			else // jump TO NEXT INDEX
				temp = temp->next;
		}
	}
}
void MyLinkedList::insertAtTail(const int& value)  // TO INSERT AT TAIL
{
	Node * temp = new Node;
	temp->data = value;
	temp->next = nullptr;
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}
void MyLinkedList::insertAtHead(const int & value) // TO INSERT AT HEAD
{
	Node * temp = new Node;
	temp->data = value;
	temp->next = nullptr;
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}
int MyLinkedList::deleteFromHead() // TO DELETE VALUE FORM HEAD
{
	if (isEmpty())
	{
		std::cout << "Liked List is empty returing NULL" << std::endl;
		//return NULL;
		return 0;
	}
	else if (head == tail)  // single node case
	{
		int RV = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return RV;
	}
	else
	{
		Node * temp = head;
		temp = temp->next;
		int RV = head->data;
		delete head;
		head = nullptr;
		head = temp;
		return RV;
	}
}
int MyLinkedList::deleteFromTail() //TO DELETE VALUE FROM TAIL
{
	if (isEmpty())
	{
		std::cout << "Liked List is empty returing NULL" << std::endl;
		//return NULL;
		return 0;
	}
	else if (head == tail)  // single node case
	{
		int RV = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return RV;
	}
	else
	{
		Node * temp = head;
		while (true)
		{
			if (temp->next == tail)
			{
				int RV = tail->data;
				delete temp->next;
				temp->next = nullptr;
				tail = temp;
				return RV;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}
void MyLinkedList::display() // TO DISPLAY THE LINKED LIST
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
	}
	else
	{
		Node * temp = head;
		while (true)
		{
			if (temp->next == nullptr)
			{
				std::cout << temp->data << std::endl;
				break;
			}
			else
			{
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}
	}
}
bool MyLinkedList::isEmpty()
{
	return (head == nullptr && tail == nullptr);
}