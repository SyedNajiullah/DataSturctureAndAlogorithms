#include"Node.h"
template<class T>
class LinkedList
{
private:
	Node<T> * head;
public:
	LinkedList();
	~LinkedList();
	Node<T> * getLinkedList() const;
};
template<class T>
LinkedList<T>::LinkedList(){
	head = nullptr;
}
template<class T>
LinkedList<T>::~LinkedList(){
	cout << "DESTROY" << endl;
}
template<class T>
Node<T> * LinkedList<T>::getLinkedList() const{
	return head;
}