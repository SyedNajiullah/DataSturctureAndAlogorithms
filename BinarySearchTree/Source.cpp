#include"BST.h"
int main(void) {

	BST<int> obj;
	obj.insert(100);
	obj.insert(50);
	obj.insert(200);
	obj.insert(25);
	obj.insert(75);
	obj.insert(150);
	obj.insert(300);
	cout << "IN" << endl;
	obj.inOrderDisplay();
	cout << endl;
	cout << "PREE" << endl;
	obj.preeOrderDisplay();
	cout << endl;
	cout << "POST" << endl;
	obj.postOrderDisplay();
	return 0;
}