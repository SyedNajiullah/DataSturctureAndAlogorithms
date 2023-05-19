#pragma once
#include"LinkedList.h"
template<class T>
class MyLinkedList :public LinkedList<T>
{
private:
	void insertAtHead(const T& value);
	void insertAtTail(const T& value);
public:
	MyLinkedList();
	~MyLinkedList();
	T deleteFromHead();
	T deleteFromTail();
	void displayFromHead();
	void displayFromTail();
	void insertSorted(const T& value);
	bool deleteValue(const T& value);
	bool isEmpty() const;
	bool isSingle() const;
};
template<class T>
MyLinkedList<T>::MyLinkedList()
{

}
template<class T>
MyLinkedList<T>::~MyLinkedList()
{
	while (!isEmpty())
	{
		deleteFromHead();
	}
}
template<class T>
void MyLinkedList<T>::insertAtHead(const T& value)
{
	Node<T> * newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (isEmpty())
	{
		LinkedList<T>::head = newNode;
		LinkedList<T>::tail = newNode;
	}
	else
	{
		newNode->next = LinkedList<T>::head;
		LinkedList<T>::head->prev = newNode;
		LinkedList<T>::head = newNode;
	}
}
template<class T>
void MyLinkedList<T>::insertAtTail(const T& value)
{
	Node<T> * newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (isEmpty())
	{
		LinkedList<T>::head = newNode;
		LinkedList<T>::tail = newNode;
	}
	else
	{
		LinkedList<T>::tail->next = newNode;
		newNode->prev = LinkedList<T>::tail;
		LinkedList<T>::tail = LinkedList<T>::tail->next;
	}
}
template<class T>
T MyLinkedList<T>::deleteFromHead()
{
	if (isEmpty())
	{
		std::cout << "Cannot delete" << std::endl;
		return NULL;
	}
	else if (isSingle())
	{
		T value = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return value;
	}
	else
	{
		LinkedList<T>::head = LinkedList<T>::head->next;
		T value = LinkedList<T>::head->prev->data;
		delete LinkedList<T>::head->prev;
		LinkedList<T>::head->prev = nullptr;
		return value;
	}

}
template<class T>
T MyLinkedList<T>::deleteFromTail()
{
	if (isEmpty())
	{
		std::cout << "Cannot delete" << std::endl;
		return NULL;
	}
	else if (isSingle())
	{
		T value = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return value;
	}
	else
	{
		LinkedList<T>::tail = LinkedList<T>::tail->prev;
		T value = LinkedList<T>::tail->next->data;
		delete LinkedList<T>::tail->next;
		LinkedList<T>::tail->next = nullptr;
		return value;
	}
}
template<class T>
void MyLinkedList<T>::displayFromHead()
{
	if (isEmpty())
	{
		std::cout << "LinkedList is empty" << std::endl;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::head;
		while (temp != nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	std::cout << std::endl;
}
template<class T>
void MyLinkedList<T>::displayFromTail()
{
	if (isEmpty())
	{
		std::cout << "LinkedList is empty" << std::endl;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::tail;
		while (temp != nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->prev;
		}
	}
	std::cout << std::endl;
}
template<class T>
void MyLinkedList<T>::insertSorted(const T& value)
{
	if (isEmpty())
	{
		insertAtHead(value); // or insert at tail means the same
	}
	else if (isSingle())
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
	else
	{
		if (value <= LinkedList<T>::head->data)
		{
			insertAtHead(value);
		}
		else if (value >= LinkedList<T>::tail->data)
		{
			insertAtTail(value);
		}
		else
		{
			Node<T> * newNode = new Node<T>;
			newNode->data = value;
			newNode->next = nullptr;
			newNode->prev = nullptr;
			Node<T> * temp = LinkedList<T>::head;
			while (true)
			{
				if (value <= temp->data && value >= temp->next->data)
				{
					temp->next->prev = newNode;
					newNode->next = temp->next;
					temp->next = newNode;
					newNode->prev = temp;
				}
				else if (temp == nullptr)
				{
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}
}
template<class T>
bool MyLinkedList<T>::deleteValue(const T& value)
{
	if (isEmpty())
	{
		std::cout << "Cannot delete" << std::endl;
		return false;
	}
	else if (isSingle())
	{
		if (value == LinkedList<T>::head->data)
		{
			deleteFromHead();
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(value == LinkedList<T>::head->data)
	{
		deleteFromHead();
		return true;
	}
	else if(value == LinkedList<T>::tail->data)
	{
		deleteFromTail();
		return true;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::head;
		while (temp->next != nullptr)
		{
			if (value == temp->next->data)
			{
				Node<T> * toDelete = temp->next;
				Node<T> * toConnect = temp->next->next;
				delete toDelete;
				toDelete = nullptr;
				temp->next = toConnect;
				toConnect->prev = temp;
			}
			else
				temp = temp->next;
		}
		return true;
	}
}
template<class T>
bool MyLinkedList<T>::isEmpty() const
{
	return (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr);
}
template<class T>
bool MyLinkedList<T>::isSingle() const
{
	return (LinkedList<T>::head->next == nullptr);
}