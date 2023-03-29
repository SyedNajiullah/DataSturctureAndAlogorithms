#include"MyQueue.h"
int main()
{
	std::cout << "\t---------------" << std::endl;
	std::cout << "\t--FOR INTEGER--" << std::endl;
	std::cout << "\t---------------" << std::endl;
	myQueue<int> obj(5);
	obj.enQueue(1);
	obj.enQueue(-2);
	obj.enQueue(999);
	obj.display();
	std::cout << "Removed Value is ->" << obj.deQueue() << std::endl;
	obj.enQueue(-200);
	obj.display();

	std::cout << "\t----------------" << std::endl;
	std::cout << "\t--FOR FLOATING--" << std::endl;
	std::cout << "\t----------------" << std::endl;
	myQueue<double> obj1(5);
	obj1.enQueue(1.1);
	obj1.enQueue(-2.8);
	obj1.enQueue(999.4);
	obj1.display();
	std::cout << "Removed Value is ->" << obj1.deQueue() << std::endl;
	obj1.enQueue(-200.7);
	obj1.display();

	std::cout << "\t----------------" << std::endl;
	std::cout << "\t--FOR CHARACTER--" << std::endl;
	std::cout << "\t----------------" << std::endl;
	myQueue<char> obj2(5);
	obj2.enQueue('A');
	obj2.enQueue('B');
	obj2.enQueue('C');
	obj2.display();
	std::cout << "Removed Value is ->" << obj2.deQueue() << std::endl;
	obj2.enQueue('D');
	obj2.display();

	return 0;
}