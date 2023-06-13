#include"BST.h"
int main(){

	BST obj;

	obj.insert(100);
	obj.insert(0);
	obj.insert(200);
	obj.insert(50);
	obj.insert(150);
	obj.insert(-3);

	obj.inOrderDisplay();
	std::cout << std::endl;
	obj.preOrderDisplay();
	std::cout << std::endl;
	obj.postOrderDisplay();
	std::cout << std::endl;
	return 0;
}