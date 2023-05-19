#include"MyLinkedList.h"

void displayDataType();
void displayMessage();

int main(void)
{
	int choose = 0;
	displayDataType();
	std::cout << "Enter choice here->";
	std::cin >> choose;
	while (true)
	{
		if (choose >= 1 && choose <= 6)
			break;
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << "Enter again ->";
			std::cin >> choose;
		}
	}
	if (choose == 1)
	{
		int c = 0;
		MyLinkedList<int> obj;
		while (true)
		{
			displayMessage();
			std::cout << "Enter your choise ->";
			std::cin >> c;
			while (true)
			{
				if (c >= 1 && c <= 9)
					break;
				else
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Enter again ->";
					std::cin >> c;
				}
			}
			if (c == 1) // insert sorted
			{
				int value = 0;
				std::cout << "Enter value ->";
				std::cin >> value;
				obj.insertSorted(value);
			}
			if (c == 2) // delete from head
			{
				int value = obj.deleteFromHead();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 3)  // delete from tail
			{
				int value = obj.deleteFromTail();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 4) // display from head
			{
				obj.displayFromHead();
			}
			if (c == 5) // display from tail
			{
				obj.displayFromTail();
			}
			if (c == 6) // delete value
			{
				int value = 0;
				std::cout << "Enter value here ->";
				std::cin >> value;
				bool isTrue = obj.deleteValue(value);
				if (isTrue)
					std::cout << "Value delete successfully" << std::endl;
				else
					std::cout << "value is not deleted" << std::endl;
			}
			if (c == 7) // is empty
			{
				bool isTrue = obj.isEmpty();
				if (isTrue)
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked List is not empty" << std::endl;
			}
			if (c == 8) // is single
			{
				bool isTrue = obj.isSingle();
				if (isTrue)
					std::cout << "There is only one node in the linked list" << std::endl;
				else
					std::cout << "Tere may be no nodes or greator then one" << std::endl;
			}
			if (c == 9) // break;
			{
				break;
			}
			
		}
	}
	if (choose == 2)
	{
		int c = 0;
		MyLinkedList<char> obj;
		while (true)
		{
			displayMessage();
			std::cout << "Enter your choise ->";
			std::cin >> c;
			while (true)
			{
				if (c >= 1 && c <= 9)
					break;
				else
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Enter again ->";
					std::cin >> c;
				}
			}
			if (c == 1) // insert sorted
			{
				char value = 0;
				std::cout << "Enter value ->";
				std::cin >> value;
				obj.insertSorted(value);
			}
			if (c == 2) // delete from head
			{
				char value = obj.deleteFromHead();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 3)  // delete from tail
			{
				char value = obj.deleteFromTail();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 4) // display from head
			{
				obj.displayFromHead();
			}
			if (c == 5) // display from tail
			{
				obj.displayFromTail();
			}
			if (c == 6) // delete value
			{
				char value = '\0';
				std::cout << "Enter value here ->";
				std::cin >> value;
				bool isTrue = obj.deleteValue(value);
				if (isTrue)
					std::cout << "Value delete successfully" << std::endl;
				else
					std::cout << "value is not deleted" << std::endl;
			}
			if (c == 7) // is empty
			{
				bool isTrue = obj.isEmpty();
				if (isTrue)
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked List is not empty" << std::endl;
			}
			if (c == 8) // is single
			{
				bool isTrue = obj.isSingle();
				if (isTrue)
					std::cout << "There is only one node in the linked list" << std::endl;
				else
					std::cout << "Tere may be no nodes or greator then one" << std::endl;
			}
			if (c == 9) // break;
			{
				break;
			}
		}
	}
	if (choose == 3)
	{
		int c = 0;
		MyLinkedList<std::string> obj;
		while (true)
		{
			displayMessage();
			std::cout << "Enter your choise ->";
			std::cin >> c;
			while (true)
			{
				if (c >= 1 && c <= 9)
					break;
				else
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Enter again ->";
					std::cin >> c;
				}
			}
			if (c == 1) // insert sorted
			{
				std::string value = "\0";
				std::cout << "Enter value ->";
				std::cin >> value;
				obj.insertSorted(value);
			}
			if (c == 2) // delete from head
			{
				std::string value = obj.deleteFromHead();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 3)  // delete from tail
			{
				std::string value = obj.deleteFromTail();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 4) // display from head
			{
				obj.displayFromHead();
			}
			if (c == 5) // display from tail
			{
				obj.displayFromTail();
			}
			if (c == 6) // delete value
			{
				std::string value = 0;
				std::cout << "Enter value here ->";
				std::cin >> value;
				bool isTrue = obj.deleteValue(value);
				if (isTrue)
					std::cout << "Value delete successfully" << std::endl;
				else
					std::cout << "value is not deleted" << std::endl;
			}
			if (c == 7) // is empty
			{
				bool isTrue = obj.isEmpty();
				if (isTrue)
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked List is not empty" << std::endl;
			}
			if (c == 8) // is single
			{
				bool isTrue = obj.isSingle();
				if (isTrue)
					std::cout << "There is only one node in the linked list" << std::endl;
				else
					std::cout << "Tere may be no nodes or greator then one" << std::endl;
			}
			if (c == 9) // break;
			{
				break;
			}
		}
	}
	if (choose == 4)
	{
		int c = 0;
		MyLinkedList<unsigned int> obj;
		while (true)
		{
			displayMessage();
			std::cout << "Enter your choise ->";
			std::cin >> c;
			while (true)
			{
				if (c >= 1 && c <= 9)
					break;
				else
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Enter again ->";
					std::cin >> c;
				}
			}
			if (c == 1) // insert sorted
			{
				unsigned int value = 0;
				std::cout << "Enter value ->";
				std::cin >> value;
				obj.insertSorted(value);
			}
			if (c == 2) // delete from head
			{
				unsigned int value = obj.deleteFromHead();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 3)  // delete from tail
			{
				unsigned int value = obj.deleteFromTail();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 4) // display from head
			{
				obj.displayFromHead();
			}
			if (c == 5) // display from tail
			{
				obj.displayFromTail();
			}
			if (c == 6) // delete value
			{
				unsigned int value = 0;
				std::cout << "Enter value here ->";
				std::cin >> value;
				bool isTrue = obj.deleteValue(value);
				if (isTrue)
					std::cout << "Value delete successfully" << std::endl;
				else
					std::cout << "value is not deleted" << std::endl;
			}
			if (c == 7) // is empty
			{
				bool isTrue = obj.isEmpty();
				if (isTrue)
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked List is not empty" << std::endl;
			}
			if (c == 8) // is single
			{
				bool isTrue = obj.isSingle();
				if (isTrue)
					std::cout << "There is only one node in the linked list" << std::endl;
				else
					std::cout << "Tere may be no nodes or greator then one" << std::endl;
			}
			if (c == 9) // break;
			{
				break;
			}
		}
	}
	if (choose == 5)
	{
		int c = 0;
		MyLinkedList<float> obj;
		while (true)
		{
			displayMessage();
			std::cout << "Enter your choise ->";
			std::cin >> c;
			while (true)
			{
				if (c >= 1 && c <= 9)
					break;
				else
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Enter again ->";
					std::cin >> c;
				}
			}
			if (c == 1) // insert sorted
			{
				float value = 0.0;
				std::cout << "Enter value ->";
				std::cin >> value;
				obj.insertSorted(value);
			}
			if (c == 2) // delete from head
			{
				float value = obj.deleteFromHead();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 3)  // delete from tail
			{
				float value = obj.deleteFromTail();
				std::cout << "Delete value ->" << value << std::endl;
			}
			if (c == 4) // display from head
			{
				obj.displayFromHead();
			}
			if (c == 5) // display from tail
			{
				obj.displayFromTail();
			}
			if (c == 6) // delete value
			{
				float value = 0.0;
				std::cout << "Enter value here ->";
				std::cin >> value;
				bool isTrue = obj.deleteValue(value);
				if (isTrue)
					std::cout << "Value delete successfully" << std::endl;
				else
					std::cout << "value is not deleted" << std::endl;
			}
			if (c == 7) // is empty
			{
				bool isTrue = obj.isEmpty();
				if (isTrue)
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked List is not empty" << std::endl;
			}
			if (c == 8) // is single
			{
				bool isTrue = obj.isSingle();
				if (isTrue)
					std::cout << "There is only one node in the linked list" << std::endl;
				else
					std::cout << "Tere may be no nodes or greator then one" << std::endl;
			}
			if (c == 9) // break;
			{
				break;
			}
		}
	}
	if (choose == 6)
	{
		std::cout << "ALLAH HAFIZ" << std::endl;
	}
	return 0;
}

void displayDataType()
{
	std::cout << "--------------" << std::endl;
	std::cout << "1. INTEGER" << std::endl;
	std::cout << "2. CHARACTER" << std::endl;
	std::cout << "3. STRING" << std::endl;
	std::cout << "4. UNSIGNED INT" << std::endl;
	std::cout << "5. FLOAT" << std::endl;
	std::cout << "6. TO EXIT" << std::endl;
	std::cout << "--------------" << std::endl;
}

void displayMessage()
{
	std::cout << "--------------------" << std::endl;
	std::cout << "1. INSERT SORTED" << std::endl;
	std::cout << "2. DELETE FROM HEAD" << std::endl;
	std::cout << "3. DELETE FROM TAIL" << std::endl;
	std::cout << "4. DISPLAY FROM HEAD" << std::endl;
	std::cout << "5. DISPLAY FROM TAIL" << std::endl;
	std::cout << "6. DELETE VALUE" << std::endl;
	std::cout << "7. ISEMPTY" << std::endl;
	std::cout << "8. ISSINGLE" << std::endl;
	std::cout << "9. EXIT" << std::endl;
	std::cout << "-------------------" << std::endl;
}