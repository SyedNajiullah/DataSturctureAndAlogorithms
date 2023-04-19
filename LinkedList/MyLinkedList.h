#include"LinkedList.h"
template<class T>
class MyLinkedList:public LinkedList<T>
{
private:
	void insertAtTail(const T& value);
	void insertAtHead(const T& value);
public:
	MyLinkedList();
	~MyLinkedList();
	T deleteFromTail();
	T deleteFromHead();
	void display();
	void insertSorted(const T& value);	
	bool deleteValue(const T& value);
	bool isEmpty() const;
};
template<class T>
MyLinkedList<T>::MyLinkedList()
{

}
template<class T>
MyLinkedList<T>::~MyLinkedList()
{

}
template<class T>
void MyLinkedList<T>::insertSorted(const T& value)
{
	if (isEmpty())
	{
		insertAtTail(value); //  or insert at head means the same
	}
	else if (LinkedList<T>::head == LinkedList<T>::tail)
	{
		if (value < LinkedList<T>::head->data)
		{
			insertAtHead(value);
		}
		else
		{
			insertAtTail(value);
		}
	}
	else
	{
		Node<T> * temp = LinkedList<T>::head;
		while (true)
		{
			if (value <= temp->data && value >= temp->next->data)
			{
				Node<T> * temp1 = new Node<T>;
				temp1->data = value;
				temp1->next = nullptr;
				temp1->next = temp->next;
				temp->next = temp;
				break;
			}
			else
				temp = temp->next;

			if (temp->next == nullptr)  // means value sab se bari hai
			{
				insertAtTail(value);
				break;
			}
		}
	}
}
template<class T>
bool MyLinkedList<T>::deleteValue(const T& value)
{
	if (isEmpty())
	{
		return false;
	}
	else if (LinkedList<T>::head == LinkedList<T>::tail)
	{
		if (value == LinkedList<T>::head->data)
		{
			delete LinkedList<T>::head;
			LinkedList<T>::head = nullptr;
			LinkedList<T>::tail = nullptr;
			return true;
		}
		else
			return false;
	}
	else if (value == LinkedList<T>::head->data)
	{
		deleteFromHead();
		return true;
	}
	else if (value == LinkedList<T>::tail->data)
	{
		deleteFromTail();
		return true;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::head;
		while (true)
		{
			if (temp->next == nullptr)
			{
				if (temp->data != value)
				{
					return false;
				}
				if (temp->data == value)
				{
					return true;
				}
			}
			else if (value == temp->next->data)
			{
				Node<T> * temp1 = temp->next;
				temp->next = temp->next->next;
				delete temp1;
				temp1 = nullptr;
				return true;
			}
			else
				temp = temp->next;
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
		LinkedList<T>::tail = temp;
	}
	else
	{
		LinkedList<T>::tail->next = temp;
		LinkedList<T>::tail = LinkedList<T>::tail->next;
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
		LinkedList<T>::tail = temp;
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
		std::cout << "Linked List is empty returning NULL" << std::endl;
		return NULL;
	}
	else if (LinkedList<T>::head == LinkedList<T>::tail) // single node case
	{
		T RV = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return RV;
	}
	else
	{
		Node<T> * temp = head;
		while (true)
		{
			if (temp->next == LinkedList<T>::tail)
			{
				T RV = LinkedList<T>::tail->data;
				delete LinkedList<T>::tail;
				LinkedList<T>::tail = temp;
				temp->next = nullptr;
				return RV;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}
template<class T>
T MyLinkedList<T>::deleteFromHead()
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty returning NULL" << std::endl;
		return NULL;
	}
	else if (LinkedList<T>::head == LinkedList<T>::tail) // single node case
	{
		T RV = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return RV;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::head->next;
		T RV = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::head = temp;
		return RV;
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
	return (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr);
}