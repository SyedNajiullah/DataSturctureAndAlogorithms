#include"LinkedList.h"
template<class T>
class MyLinkedList: public LinkedList<T>
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
MyLinkedList<T>::MyLinkedList(const MyLinkedList<T> & obj)
{
	Node<T>* current = LinkedList<T>::tail->next;
	Node<T>* breakN = LinkedList<T>::tail->next;
	while (current->next != breakN)
	{
		insertAtTail(current->data);
		current = current->next;
	}
}
template<class T>
T MyLinkedList<T>::deleteFromTail()
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
		return NULL;
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		T returningValue = LinkedList<T>::tail->data;
		delete LinkedList<T>::tail;
		LinkedList<T>::tail = nullptr;
		return returningValue;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::tail->next;
		while (temp->next != LinkedList<T>::tail)
		{
			temp = temp->next;
		}
		T RV = LinkedList<T>::tail->data;
		temp->next = LinkedList<T>::tail->next;
		delete LinkedList<T>::tail;
		LinkedList<T>::tail = temp;
		return RV;
	}
}
template<class T>
T MyLinkedList<T>::deleteFromHead()
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
		return NULL;
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		int returningValue = LinkedList<T>::tail->data;
		delete LinkedList<T>::tail;
		LinkedList<T>::tail = nullptr;
		return returningValue;
	}
	else
	{
		T rv = LinkedList<T>::tail->next->data;
		Node<T> * temp = LinkedList<T>::tail->next;
		LinkedList<T>::tail->next = tail->next->next;
		delete temp;
		temp = nullptr;
		return rv;
	}
}
template<class T>
void MyLinkedList<T>::display()
{
	if (isEmpty())
	{
		std::cout << "LinkedList is empty" << std::endl;
	}
	else
	{
		Node<T>* temp = LinkedList<T>::tail->next;
		while (true)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
			if (temp == LinkedList<T>::tail->next)
			{
				break;
			}
		}
		std::cout << std::endl;
	}
}
template<class T>
void MyLinkedList<T>::insertSorted(const T& value)
{
	if (isEmpty())
	{
		insertAtHead(value);
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		if (value <= LinkedList<T>::tail->data)
		{
			insertAtHead(value);
		}
		else
		{
			insertAtTail(value);
		}
	}
	else if (value <= LinkedList<T>::tail->next->data)
	{
		insertAtHead(value);
	}
	else if (value >= LinkedList<T>::tail->data)
	{
		insertAtTail(value);
	}
	else
	{
		Node<T> * temp = LinkedList<T>::tail->next;
		while (true)
		{
			if (value >= temp->data && value <= temp->next->data)
			{
				Node<T> * newNode = new Node<T>;
				newNode->data = value;
				newNode->next = nullptr;
				newNode->next = temp->next;
				temp->next = newNode;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}
template<class T>
bool MyLinkedList<T>::deleteValue(const T& value)
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
		return false;
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		if (value == LinkedList<T>::tail->data)
		{
			delete LinkedList<T>::tail;
			LinkedList<T>::tail = nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (value == LinkedList<T>::tail->data)
	{
		deleteFromTail();
		return true;
	}
	else if (value == LinkedList<T>::tail->next->data)
	{
		deleteFromHead();
		return true;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::tail->next;
		while (true)
		{
			if (value == temp->next->data)
			{
				Node<T> * temp1 = temp->next;
				temp->next = temp->next->next;
				delete temp1;
				temp1 = nullptr;
				return true;
			}
			else
			{
				temp = temp->next;
			}
			if (temp == LinkedList<T>::tail->next)
			{
				return false;
			}
		}
	}
}
template<class T>
bool MyLinkedList<T>::isEmpty() const
{
	if (LinkedList<T>::tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
void MyLinkedList<T>::removeDublicate()
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		std::cout << "There can be no dublicates" << std::endl;
	}
	else
	{
		int length = getNumberOFNodes();
		int * arr = new int[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = deleteFromHead();
		}
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (arr[i] == arr[j])
				{
					for (int l = j; l < length - 1; l++)
					{
						arr[l] = arr[l + 1];
					}
					length--;
				}
			}
		}
		for (int i = 0; i < length; i++)
		{
			insertAtTail(arr[i]);
		}
	}
}
template<class T>
void MyLinkedList<T>::insertAtTail(const T& value)
{
	Node<T> * newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	if (isEmpty())
	{
		LinkedList<T>::tail = newNode;
		LinkedList<T>::tail->next = LinkedList<T>::tail;
	}
	else
	{
		newNode->next = LinkedList<T>::tail->next;
		LinkedList<T>::tail->next = newNode;
		LinkedList<T>::tail = LinkedList<T>::tail->next;
	}
}
template<class T>
void MyLinkedList<T>::insertAtHead(const T& value)
{
	Node<T> * newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	if (isEmpty())
	{
		LinkedList<T>::tail = newNode;
		LinkedList<T>::tail->next = LinkedList<T>::tail;
	}
	else
	{
		newNode->next = LinkedList<T>::tail->next;
		LinkedList<T>::tail->next = newNode;
	}
}
template<class T>
int MyLinkedList<T>::getNumberOFNodes()
{
	int count = 0;
	Node<T>* temp = LinkedList<T>::tail->next;
	while (true)
	{
		count++;
		temp = temp->next;
		if (temp == LinkedList<T>::tail->next)
		{
			break;
		}
	}
	return count;
}
template<class T>
void MyLinkedList<T>::insertInBetween(const T& value)
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" <<std::endl;
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		std::cout << "Cannot insert in between" << std::endl;
	}
	else
	{
		Node<T> * temp = LinkedList<T>::tail->next;
		int length = getNumberOFNodes();
		length = length / 2;
		for (int i = 0; i < length - 1; i++)
		{
			temp = temp->next;
		}
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		newNode->next = temp->next;
		temp->next = newNode;
	}
}
template<class T>
void MyLinkedList<T>::sort()
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		std::cout << "Cannot sort" << std::endl;
	}
	else
	{
		int length = getNumberOFNodes();
		int * arr = new int[length];
		int value = 0;
		for (int i = 0; i < length; i++)
		{
			arr[i] = deleteFromHead();
		}
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (arr[i] > arr[j])
				{
					value = arr[i];
					arr[i] = arr[j];
					arr[j] = value;
				}
			}
		}
		for (int i = 0; i < length; i++)
		{
			insertAtHead(arr[i]);
		}
	}
}
template<class T>
void MyLinkedList<T>::reverse()
{
	if (isEmpty())
	{
		std::cout << "Linked List is empty" << std::endl;
	}
	else if (LinkedList<T>::tail->next == LinkedList<T>::tail)
	{
		std::cout << "Cannot reverse" << std::endl;
	}
	else
	{
		int length = getNumberOFNodes();
		int * arr = new int[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = deleteFromHead();
		}
		int i = 0;
		int * reverseArr = new int[length];
		for (int j = length - 1; j >= 0; j--)
		{
			reverseArr[i++] = arr[j];
		}
		for (int i = 0; i < length; i++)
		{
			insertAtTail(reverseArr[i]);
		}
	}
}
