#include"MyLinkedList.h"
int main(void)
{
	MyLinkedList obj;
	obj.insertSorted(45);
	obj.insertSorted(-1);
	obj.insertSorted(0);
	obj.insertSorted(1122);
	obj.insertSorted(15);
	obj.display();
	std::cout << "Deleting value" << std::endl;
	std::cout << obj.deleteValue(45) << std::endl;
	std::cout << '\n' << std::endl;
	obj.display();
	std::cout << '\n' << std::endl;
	std::cout << obj.deleteValue(-1) << std::endl;
	std::cout << obj.deleteValue(0) << std::endl;
	std::cout << obj.deleteValue(1122) << std::endl;
	return 0;
}