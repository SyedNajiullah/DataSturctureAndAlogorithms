#include"MyLinkedList.h"

void displayDataType();
void displayTaskToPerform();

int main(void)
{
	int choose = 0;
	displayDataType();
	std::cin >> choose;
	while (true)
	{
		if (choose > 0 && choose < 7)
			break;
		else
		{
			std::cout << "Please enter a valid input ->";
			std::cin >> choose;
		}
	}
	if (choose == 1) // FOR INTEGER 
	{
		MyLinkedList<int> obj;
		while (true)
		{
			int choose1 = 0;
			displayTaskToPerform();
			std::cout << "Enter you choice ->";
			std::cin >> choose1;
			while (true)
			{
				if (choose1 > 0 && choose1 < 8)
					break;
				else
				{
					std::cout << "Please enter a valid input ->" << std::endl;
					std::cin >> choose1;
				}
			}
			if (choose1 == 1)  // INSERT SORTED 
			{
				int value = 0;
				std::cout << "Enter value to be inserted ->";
				std::cin >> value;
				obj.insertSorted(value);

			}
			if (choose1 == 2) // DELETE FROM HEAD
			{
				obj.deleteFromHead();
			}
			if (choose1 == 3) // DELETE FROM TAIL
			{
				obj.deleteFromTail();
			}
			if (choose1 == 4) // DELETE A VALUE
			{
				int value = 0;
				std::cout << "Enter value to be deleted ->";
				std::cin >> value;
				std::cout << "Delete value ->" << obj.deleteValue(value) << std::endl;
			}
			if (choose1 == 5) // DISPLAY
			{
				obj.display();
			}
			if (choose1 == 6)  // ISEMPTY
			{
				if (obj.isEmpty())
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked list is not empty" << std::endl;
			}
			if (choose1 == 7)  // EXIT
			{
				break;
			}
		}
	}
	if (choose == 2)  // CHARECTER
	{
		MyLinkedList<char> obj;
		while (true)
		{
			int choose1 = 0;
			displayTaskToPerform();
			std::cout << "Enter you choice ->";
			std::cin >> choose1;
			while (true)
			{
				if (choose1 > 0 && choose1 < 8)
					break;
				else
				{
					std::cout << "Please enter a valid input ->" << std::endl;
					std::cin >> choose1;
				}
			}
			if (choose1 == 1)  // INSERT SORTED 
			{
				char value = '\0';
				std::cout << "Enter value to be inserted ->";
				std::cin >> value;
				obj.insertSorted(value);

			}
			if (choose1 == 2) // DELETE FROM HEAD
			{
				obj.deleteFromHead();
			}
			if (choose1 == 3) // DELETE FROM TAIL
			{
				obj.deleteFromTail();
			}
			if (choose1 == 4) // DELETE A VALUE
			{
				char value = '\0';
				std::cout << "Enter value to be deleted ->";
				std::cin >> value;
				std::cout << "Delete value ->" << obj.deleteValue(value) << std::endl;
			}
			if (choose1 == 5) // DISPLAY
			{
				obj.display();
			}
			if (choose1 == 6)  // ISEMPTY
			{
				if (obj.isEmpty())
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked list is not empty" << std::endl;
			}
			if (choose1 == 7)  // EXIT
			{
				break;
			}
		}
	}
	if (choose == 3)  // STRING 
	{
		MyLinkedList<std::string> obj;
		while (true)
		{
			int choose1 = 0;
			displayTaskToPerform();
			std::cout << "Enter you choice ->";
			std::cin >> choose1;
			while (true)
			{
				if (choose1 > 0 && choose1 < 8)
					break;
				else
				{
					std::cout << "Please enter a valid input ->" << std::endl;
					std::cin >> choose1;
				}
			}
			if (choose1 == 1)  // INSERT SORTED 
			{
				std::string value = "\0";
				std::cout << "Enter value to be inserted ->";
				std::cin >> value;
				obj.insertSorted(value);

			}
			if (choose1 == 2) // DELETE FROM HEAD
			{
				obj.deleteFromHead();
			}
			if (choose1 == 3) // DELETE FROM TAIL
			{
				obj.deleteFromTail();
			}
			if (choose1 == 4) // DELETE A VALUE
			{
				std::string value = "\0";
				std::cout << "Enter value to be deleted ->";
				std::cin >> value;
				std::cout << "Delete value ->" << obj.deleteValue(value) << std::endl;
			}
			if (choose1 == 5) // DISPLAY
			{
				obj.display();
			}
			if (choose1 == 6)  // ISEMPTY
			{
				if (obj.isEmpty())
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked list is not empty" << std::endl;
			}
			if (choose1 == 7)  // EXIT
			{
				break;
			}
		}
	}
	if (choose == 4)  // FLOAT 
	{
		MyLinkedList<float> obj;
		while (true)
		{
			int choose1 = 0;
			displayTaskToPerform();
			std::cout << "Enter you choice ->";
			std::cin >> choose1;
			while (true)
			{
				if (choose1 > 0 && choose1 < 8)
					break;
				else
				{
					std::cout << "Please enter a valid input ->" << std::endl;
					std::cin >> choose1;
				}
			}
			if (choose1 == 1)  // INSERT SORTED 
			{
				float value = 0.0;
				std::cout << "Enter value to be inserted ->";
				std::cin >> value;
				obj.insertSorted(value);

			}
			if (choose1 == 2) // DELETE FROM HEAD
			{
				obj.deleteFromHead();
			}
			if (choose1 == 3) // DELETE FROM TAIL
			{
				obj.deleteFromTail();
			}
			if (choose1 == 4) // DELETE A VALUE
			{
				float value = 0.0;
				std::cout << "Enter value to be deleted ->";
				std::cin >> value;
				std::cout << "Delete value ->" << obj.deleteValue(value) << std::endl;
			}
			if (choose1 == 5) // DISPLAY
			{
				obj.display();
			}
			if (choose1 == 6)  // ISEMPTY
			{
				if (obj.isEmpty())
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked list is not empty" << std::endl;
			}
			if (choose1 == 7)  // EXIT
			{
				break;
			}
		}
	}
	if (choose == 5) // FOR UNSIGNED INT 
	{
		MyLinkedList<unsigned int> obj;
		while (true)
		{
			int choose1 = 0;
			displayTaskToPerform();
			std::cout << "Enter you choice ->";
			std::cin >> choose1;
			while (true)
			{
				if (choose1 > 0 && choose1 < 8)
					break;
				else
				{
					std::cout << "Please enter a valid input ->" << std::endl;
					std::cin >> choose1;
				}
			}
			if (choose1 == 1)  // INSERT SORTED 
			{
				unsigned int value = 0;
				std::cout << "Enter value to be inserted ->";
				std::cin >> value;
				obj.insertSorted(value);

			}
			if (choose1 == 2) // DELETE FROM HEAD
			{
				obj.deleteFromHead();
			}
			if (choose1 == 3) // DELETE FROM TAIL
			{
				obj.deleteFromTail();
			}
			if (choose1 == 4) // DELETE A VALUE
			{
				unsigned int value = 0;
				std::cout << "Enter value to be deleted ->";
				std::cin >> value;
				std::cout << "Delete value ->" << obj.deleteValue(value) << std::endl;
			}
			if (choose1 == 5) // DISPLAY
			{
				obj.display();
			}
			if (choose1 == 6)  // ISEMPTY
			{
				if (obj.isEmpty())
					std::cout << "Linked List is empty" << std::endl;
				else
					std::cout << "Linked list is not empty" << std::endl;
			}
			if (choose1 == 7)  // EXIT
			{
				break;
			}
		}
	}
	return 0;
}
void displayDataType()
{
	std::cout << "---------------------" << std::endl;
	std::cout << "1.  FOR INTEGER" << std::endl;
	std::cout << "2.  FOR CHARECTER" << std::endl;
	std::cout << "3.  FOR STRING" << std::endl;
	std::cout << "4.  FOR FLOAT" << std::endl;
	std::cout << "5.  FOR UNSIGNED INT" << std::endl;
	std::cout << "6.  FOR EXIT" << std::endl;
	std::cout << "---------------------" << std::endl;
}
void displayTaskToPerform()
{
	std::cout << "---------------------" << std::endl;
	std::cout << "1.  FOR INSERT SORTED" << std::endl;
	std::cout << "2.  FOR DELETE FROM HEAD" << std::endl;
	std::cout << "3.  FOR DELETE FROM TAIL" << std::endl;
	std::cout << "4.  FOR DELETE A VALUE" << std::endl;
	std::cout << "5.  FOR DISPLAY" << std::endl;
	std::cout << "6.  FOR ISEMPTY" << std::endl;
	std::cout << "7.  FOR EXIT" << std::endl;
	std::cout << "---------------------" << std::endl;
}
/*MyLinkedList<int> obj;
obj.insertSorted(2);
obj.insertSorted(1);
obj.insertSorted(3);
obj.insertSorted(4);
obj.insertSorted(5);
obj.display();
std::cout << "Delete value ->" << obj.deleteValue(1) << std::endl;
std::cout << "Delete value ->" << obj.deleteValue(5) << std::endl;
std::cout << "Delete value ->" << obj.deleteValue(3) << std::endl;
std::cout << "Delete value ->" << obj.deleteValue(200) << std::endl;
std::cout << "Delete value ->" << obj.deleteValue(2) << std::endl;
std::cout << "Delete value ->" << obj.deleteValue(4) << std::endl;
obj.display();*/