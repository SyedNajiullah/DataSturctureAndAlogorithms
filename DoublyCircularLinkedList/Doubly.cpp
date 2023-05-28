#include"DCLL.h"
int main(void) {
	DCLL<int> obj;
	obj.insertAtTail(1);
	obj.insertAtTail(2);
	obj.insertAtTail(3);
	obj.insertAtTail(4);
	obj.insertAtTail(5);
	obj.display();
	std::cout << "Delete from tail :" << obj.deleteFromTail() << std::endl;
	obj.display();
	std::cout << "Delete from tail :" << obj.deleteFromTail() << std::endl;
	obj.display();
	std::cout << "Delete from tail :" << obj.deleteFromTail() << std::endl;
	obj.display();
	std::cout << "Delete from tail :" << obj.deleteFromTail() << std::endl;
	obj.display();
	std::cout << "Delete from tail :" << obj.deleteFromTail() << std::endl;
	obj.display();
	std::cout << "Delete from tail :" << obj.deleteFromTail() << std::endl;
	obj.display();
	return 0;
}