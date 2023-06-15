#include "BST.h"

void BST::INORDERDISPLAY(Node* root) const{
	if (root == nullptr){
		return;
	}
	INORDERDISPLAY(root->getLeftChild());
	for (int i = 0; i < root->getCount(); i++){
		cout << root->getData() << " ";
	}
	INORDERDISPLAY(root->getRightChild());
}
void BST::PREORDERDISPLAY(Node* root) const{
	if (root == nullptr){
		return;
	}
	for (int i = 0; i < root->getCount(); i++){
		cout << root->getData() << " ";
	}
	PREORDERDISPLAY(root->getLeftChild());
	PREORDERDISPLAY(root->getRightChild());
}
void BST::POSTORDER(Node* root) const{
	if (root == nullptr){
		return;
	}
	POSTORDER(root->getLeftChild());
	POSTORDER(root->getRightChild());
	for (int i = 0; i < root->getCount(); i++){
		cout << root->getData() << " ";
	}
}

BST::BST() :Tree(){

}


BST::~BST(){
	if (root != nullptr){
		deleteValue(root->getData());
	}
}

void BST::insert(const int& value){
	if (root == nullptr){
		root = new Node(value, 1, nullptr, nullptr);
	}
	else{
		Node* temp = root;
		while (true){
			if (value == temp->getData()){
				int set = temp->getCount();
				set = set + 1;
				temp->setCount(set);
				break;
			}
			else if (value < temp->getData()){
				if (temp->getLeftChild() == nullptr){
					temp->setLeftChild(new Node(value, 1, nullptr, nullptr));
					break;
				}
				else{
					temp = temp->getLeftChild();
				}
			}
			else{
				if (temp->getRightChild() == nullptr){
					temp->setRightChild(new Node(value, 1, nullptr, nullptr));
					break;
				}
				else{
					temp = temp->getRightChild();
				}
			}
		}
	}

}
void BST::inorderDisplay() const{
	if (root == nullptr){
		cout << "Tree is empty" << endl;
	}
	else{
		INORDERDISPLAY(root);
	}
}
void BST::preorderDisplay() const{
	if (root == nullptr){
		cout << "Tree is empty" << endl;
	}
	else{
		PREORDERDISPLAY(root);
	}
}
void BST::postorderDisplay() const{
	if (root == nullptr){
		cout << "Tree is empty" << endl;
	}
	else{
		POSTORDER(root);
	}
}
bool BST::deleteValue(int value){
	if (root == nullptr){
		return false;
	}
	else if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr){
		if (value == root->getData()){
			if (root->getCount() == 1){
				delete root;
				root = nullptr;
				return true;
			}
			else{
				int count = root->getCount();
				count = count - 1;
				root->setCount(count);
				return true;
			}
		}
		else{
			return false;
		}
	}
	else if (value == root->getData() && root->getLeftChild() != nullptr && root->getRightChild() == nullptr){
		if (root->getCount() == 1){
			Node* temp = root;
			root = root->getLeftChild();
			delete temp;
			temp = nullptr;
			return true;
		}
		else{
			int count = root->getCount();
			count = count - 1;
			root->setCount(count);
			return true;
		}
	}
	else if (value == root->getData() && root->getLeftChild() == nullptr && root->getRightChild() != nullptr){
		if (root->getCount() == 1){
			Node* temp = root;
			root = root->getRightChild();
			delete temp;
			temp = nullptr;
			return true;
		}
		else{
			int count = root->getCount();
			count = count - 1;
			root->setCount(count);
			return true;
		}
	}
	else{// FINDING PARENT AND NODE TO BE DELETED
		Node* parent = root;
		Node* toDelete = root;
		while (true){
			if (toDelete == nullptr){
				return false; // means value was not in the tree
			}
			if (value == toDelete->getData()){
				break;
			}
			else if (value < toDelete->getData()){
				parent = toDelete;
				toDelete = toDelete->getLeftChild();
			}
			else{
				parent = toDelete;
				toDelete = toDelete->getRightChild();
			}
		}
		if (toDelete->getLeftChild() != nullptr && toDelete->getRightChild() != nullptr){
			Node* del = toDelete;
			parent = del;
			toDelete = toDelete->getRightChild();
			if (toDelete != nullptr){
				while (toDelete->getLeftChild() != nullptr){
					parent = toDelete;
					toDelete = toDelete->getLeftChild();
				}
			}
			del->setData(toDelete->getData());
			del->setCount(toDelete->getCount());
			value = toDelete->getData();
		}
		if (toDelete->getLeftChild() == nullptr && toDelete->getRightChild() == nullptr){
			if (toDelete->getCount() == 1){
				if (value < parent->getData()){
					delete toDelete;
					toDelete = nullptr;
					parent->setLeftChild(nullptr);
					return true;
				}
				else{
					delete toDelete;
					toDelete = nullptr;
					parent->setRightChild(nullptr);
					return true;
				}
			}
			else{
				int count = toDelete->getCount();
				count = count - 1;
				toDelete->setCount(count);
				return true;
			}
		}
		if (toDelete->getLeftChild() != nullptr && toDelete->getRightChild() == nullptr){
			if (toDelete->getCount() == 1){
				if (value < parent->getData()){
					parent->setLeftChild(toDelete->getLeftChild());
					delete toDelete;
					toDelete = nullptr;
					return true;
				}
				else{
					parent->setRightChild(toDelete->getLeftChild());
					delete toDelete;
					toDelete = nullptr;
					return true;
				}
			}
			else{
				int count = toDelete->getCount();
				count = count - 1;
				toDelete->setCount(count);
				return true;
			}
		}
		if (toDelete->getLeftChild() == nullptr && toDelete->getRightChild() != nullptr){
			if (toDelete->getCount() == 1){
				if (value < toDelete->getData()){
					parent->setLeftChild(toDelete->getRightChild());
					delete toDelete;
					toDelete = nullptr;
					return true;
				}
				else{
					parent->setRightChild(toDelete->getRightChild());
					delete toDelete;
					toDelete = nullptr;
					return true;
				}
			}
			else{
				int count = toDelete->getCount();
				count = count - 1;
				toDelete->setCount(count);
				return true;
			}
		}
	}
}
bool BST::searchValue(const int& value) const{
	if (root == nullptr){
		return false;
	}
	else{
		Node* temp = root;
		while (temp != nullptr){
			if (value == temp->getData()){
				return true;
			}
			else if (value < temp->getData()){
				temp = temp->getLeftChild();
			}
			else{
				temp = temp->getRightChild();
			}
		}
		return false;
	}
}
