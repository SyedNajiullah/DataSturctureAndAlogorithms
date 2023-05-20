#include"LinkedList.h"

template<class T>
Node<T> * insertAtTail(Node<T> * head, const T& value);
template<class T>
Node<T> * insertAtHead(Node<T> * head, const T& value);
template<class T>
void display(Node<T> * head);
template<class T>
Node<T> * deleteFromHead(Node<T> *head);
template<class T>
Node<T> * deleteFromTail(Node<T> *head);
template<class T>
Node<T> * insertSorted(Node<T> *head, const T& value);
template<class T>
Node<T> * deleteValue(Node<T> * head, const T& value);
template<class T>
void deleteAllNodes(Node<T> * head);

int main(){

	LinkedList<int> obj;
	Node<int>* head = obj.getLinkedList();
	head = insertSorted(head, 2);
	head = insertSorted(head, 3);
	head = insertSorted(head, 400);
	head = insertSorted(head, 500);
	head = insertSorted(head, 45);
	display(head);
	head = deleteValue(head, 2);
	display(head);
	deleteAllNodes(head);
	return 0;
}

template<class T>
void deleteAllNodes(Node<T> * head){
	if (head == nullptr){
		cout << "LinkedList is empty" << endl;
	}
	else{
		while (head != nullptr){
			head = deleteFromHead(head);
		}
	}
}
template<class T>
Node<T> * deleteValue(Node<T> * head, const T& value){
	if (head == nullptr){
		cout << "Cannot delete" << endl;
		return head;
	}
	else if (head->next == nullptr){
		if (value == head->data){
			return deleteFromHead(head);
		}
		else{
			return head;
		}
	}
	else if (value == head->data){
		return deleteFromHead(head);
	}
	else{
		Node<T> * i = head;
		while (true){
			if (i == nullptr){
				return head;
			}
			else if (value == i->next->data){
				if (i->next->next == nullptr){
					delete i->next;
					i->next = nullptr;
				}
				else{
					Node<T> * toConnect = i->next->next;
					delete i->next;
					i->next = toConnect;
					toConnect->prev = i;
					return head;
				}
			}
			i = i->next;
		}
	}
}

template<class T>
Node<T> * insertSorted(Node<T> *head, const T& value){
	if (head == nullptr){
		return insertAtTail(head, value);
	}
	else if (head->next == nullptr){
		if (value > head->data){
			return insertAtTail(head, value);
		}
		else{
			return insertAtHead(head, value);
		}
	}
	else if (value <= head->data){
		return insertAtHead(head, value);
	}
	else{
		Node<T> * i = head;
		while (true){
			if (i->next == nullptr){
				return insertAtTail(head, value);
			}
			else if (value >= i->data && value <= i->next->data){
				Node<T> * newNode = new Node<T>;
				newNode->data = value;
				newNode->next = nullptr;
				newNode->prev = nullptr;
				i->next->prev = newNode;
				newNode->next = i->next;
				i->next = newNode;
				newNode->prev = i;
				return head;
			}
			i = i->next;
		}
	}
}

template<class T>
Node<T> * deleteFromTail(Node<T> *head){
	if (head == nullptr){
		cout << "Cannot delete" << endl;
		return head;
	}
	else if (head->next == nullptr){
		delete head;
		head = nullptr;
		return head;
	}
	else{
		Node<T> * tail = head;
		while (tail->next->next != nullptr){
			tail = tail->next;
		}
		delete tail->next;
		tail->next = nullptr;
		return head;
	}
}

template<class T>
Node<T> * deleteFromHead(Node<T> *head){
	if (head == nullptr){
		cout << "Cannot delete" << endl;
		return head;
	}
	else if (head->next == nullptr){
		delete head;
		head = nullptr;
		return head;
	}
	else{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
		return head;
	}
}

template<class T>
void display(Node<T> * head){
	if (head == nullptr){
		cout << "Linked List is empty" << endl;
	}
	else{
		for (Node<T> * i = head; i != nullptr; i = i->next){
			cout << i->data << " ";
		}
		cout << endl;
	}
}

template<class T>
Node<T> * insertAtHead(Node<T> * head, const T& value){
	Node<T> * newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr){
		head = newNode;
	}
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	return head;
}

template<class T>
Node<T> * insertAtTail(Node<T> * head, const T& value){
	Node<T> * newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr){
		head = newNode;
	}
	else
	{
		Node<T> * tail = head;
		while (tail->next != nullptr){
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->prev = tail;
	}
	return head;
}