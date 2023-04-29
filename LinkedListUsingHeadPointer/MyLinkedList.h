#include"LinkedList.h"
template<class T>
class MyLinkedList:public LinkedList<T>
{
public:
	MyLinkedList();
	~MyLinkedList();
	MyLinkedList(const MyLinkedList<T> & obj);

	T deleteFromTail();
	T deleteFromHead();
	void display();
	void insertSorted(const T& value);	
	bool deleteValue(const T& value);
	bool isEmpty() const;
	void removeDublicate();
	void insertAtTail(const T& value);
	void insertAtHead(const T& value);
	int getNumberOFNodes();
	void insertInBetween(const T& value);
	void sort();
	void reverse();
};
template<class T>
MyLinkedList<T>::MyLinkedList(const MyLinkedList<T> & obj)
{
	Node<T>* current = obj.head;
	while (current != nullptr)
	{
		insertAtTail(current->data);
		current = current->next;
	}
}
template<class T>
void MyLinkedList<T>::reverse()
{
	int length = getNumberOFNodes();
	int * arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = deleteFromHead();
	}
	int i = 0;
	int *reverseArr = new int[length];
	for (int j = length - 1; j >= 0; j--)
	{
		reverseArr[i++] = arr[j];
	}
	for (int i = 0; i < length; i++)
	{
		insertAtTail(reverseArr[i]);
	}
}
template<class T>
void MyLinkedList<T>::sort()
{
	if (isEmpty())
	{
		std::cout << "Linked list is empty" << std::endl;
	}
	else if (LinkedList<T>::head->next == nullptr)
	{
		std::cout << "LL is already sorted" << std::endl;
	}
	else
	{
		T value = NULL;
		for (Node<T>* i = LinkedList<T>::head; i != nullptr; i = i->next)
		{
			for (Node<T>* j = i->next; j != nullptr; j = j->next)
			{
				if (i->data > j->data)
				{
					value = i->data;
					i->data = j->data;
					j->data = value;
				}
			}
		}
	}
}
template<class T>
int MyLinkedList<T>::getNumberOFNodes()
{
	Node<T> * temp = LinkedList<T>::head;
	int count = 0;
	while (temp != nullptr)
	{
		count += 1;
		temp = temp->next;
	}
	return count;
}
template<class T>
void MyLinkedList<T>::insertInBetween(const T& value)
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
	}
	else if (LinkedList<T>::head->next == nullptr)
	{
		std::cout << "Only one node in linked list" << std::endl;
		std::cout << "Cannot insert in bertween" << std::endl;
	}
	else
	{
		int length = getNumberOFNodes();
		length = length / 2;
		Node<T> * temp = LinkedList<T>::head;
		for (int i = 0; i < length - 1; i++)
		{
			temp = temp->next;
		}
		Node<T> * newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		newNode->next = temp->next;
		temp->next = newNode;
	}
}
template<class T>
void MyLinkedList<T>::removeDublicate()
{
	if (isEmpty())
	{
		std::cout << "Linked list is empty" << std::endl;
	}
	else if(LinkedList<T>::head->next == nullptr)
	{
		std::cout << "LL cannot have dublicate values" << std::endl;
	}
	else
	{
		T value = NULL;
		for (Node<T>* i = LinkedList<T>::head; i != nullptr; i = i->next)
		{
			for (Node<T> * j = i; j != nullptr; j = j->next)
			{
				if (j->next == nullptr)
				{
					break;
				}
				if (i->data == j->next->data)
				{
					Node<T> * temp = j->next;
					j->next = j->next->next;
					delete temp;
					temp = nullptr;
				}
			}
		}
	}
}
template<class T>
MyLinkedList<T>::MyLinkedList()
{

}
template<class T>
MyLinkedList<T>::~MyLinkedList()
{
	int length = getNumberOFNodes();
	for (int i = 0; i < length; i++)
	{
		deleteFromHead();
	}
}
template<class T>
void MyLinkedList<T>::insertSorted(const T& value)
{
	if (isEmpty())
	{
		insertAtHead(value); // or insertAtTail() means the same;
	}
	else if (LinkedList<T>::head->next == nullptr)
	{
		if (value <= LinkedList<T>::head->data)
		{
			insertAtHead(value);
		}
		else
		{
			insertAtTail(value);
		}
	}
	else if (value <= LinkedList<T>::head->data)
	{
		insertAtHead(value);
	}
	else
	{
		Node<T> * temp1 = LinkedList<T>::head;
		while (true)
		{
			if (temp1->next == nullptr)
			{
				insertAtTail(value);
				break;
			}
			if (value >= temp1->data && value <= temp1->next->data)
			{
				Node<T> * temp2 = new Node<T>;
				temp2->data = value;
				temp2->next = nullptr;
				temp2->next = temp1->next;
				temp1->next = temp2;
				break;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
	}
	
}
template<class T>
bool MyLinkedList<T>::deleteValue(const T& value)
{
	Node<T> * temp = LinkedList<T>::head; // temp will act as tail in this case
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	if (isEmpty())
	{
		std::cout << "Canot delete a value" << std::endl;
		return false;
	}
	else if (LinkedList<T>::head->next == nullptr) // singe node case
	{
		if (LinkedList<T>::head->data == value)
		{
			deleteFromHead();
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (value == LinkedList<T>::head->data)
	{
		deleteFromHead();
		return true;
	}
	else if (value == temp->data)
	{
		deleteFromTail();
		return true;
	}
	else
	{
		Node<T> * temp1 = LinkedList<T>::head;
		while (true)
		{
			if (temp1->next == nullptr)
			{
				return false;
			}
			if (value == temp1->next->data)
			{
				Node<T> * temp3 = temp1->next;
				temp1->next = temp3->next->next;
				delete temp3;
				temp3 = nullptr;
				return true;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
	}
}
template<class T>
void MyLinkedList<T>::insertAtTail(const T& value)
{
	Node<T> * temp = new Node<T>;
	temp->data = value;
	temp->next = nullptr;
	if (isEmpty())
	{
		LinkedList<T>::head = temp;
	}
	else
	{
		Node<T> * temp1 = LinkedList<T>::head; // temp1 will act as tail in this case
		while (temp1->next != nullptr)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}
template<class T>
void MyLinkedList<T>::insertAtHead(const T& value)
{
	Node<T> * temp = new Node<T>;
	temp->data = value;
	temp->next = nullptr;
	if (isEmpty())
	{
		LinkedList<T>::head = temp;
	}
	else
	{
		temp->next = LinkedList<T>::head;
		LinkedList<T>::head = temp;
	}
}
template<class T>
T MyLinkedList<T>::deleteFromTail()
{
	if (isEmpty())
	{
		std::cout << "cannot delete a value" << std::endl;
		return NULL;
	}
	else if (LinkedList<T>::head->next == nullptr)
	{
		T RV = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		return RV;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		T RV = temp->next->data;
		delete temp->next;
		temp->next = nullptr;
		return RV;
	}
}
template<class T>
T MyLinkedList<T>::deleteFromHead()
{
	if (isEmpty())
	{
		std::cout << "cannot delete a value" << std::endl;
		return NULL;
	}
	else if (LinkedList<T>::head->next == nullptr)
	{
		T RV = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		return RV;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::head;
		LinkedList<T>::head = LinkedList<T>::head->next;
		T value = temp->data;
		delete temp;
		temp = nullptr;
		return value;
	}
}
template<class T>
void MyLinkedList<T>::display()
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
	}
	else
	{
		std::cout << "--------------------------" << std::endl;
		std::cout << "-----(LINKED LIST IS)-----" << std::endl;
		std::cout << "--------------------------" << std::endl;
		Node<T> * temp = LinkedList<T>::head;
		while (true)
		{
			if (temp->next == nullptr)
			{
				std::cout << temp->data << std::endl;
				break;
			}
			else
			{
				std::cout << temp->data << " ";
				temp = temp->next;
			}
		}
	}
}
template<class T>
bool MyLinkedList<T>::isEmpty() const
{
	return (LinkedList<T>::head == nullptr);
}