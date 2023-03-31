#include"MyStack.h"

void displayDataTypeOption();
void displayTaskToPerform();

int main()
{
	int chooseForDataType = 0;
	int chooseFortask = 0;
	int size = 0;
	displayDataTypeOption();
	std::cin >> chooseForDataType;
	if (chooseForDataType != 5)
	{
		std::cout << "ENTER MAX SIZE OF STACK:";
		std::cin >> size;
	}
	if (chooseForDataType == 1) //FOR INTEGER
	{
		MyStack<int> obj(size);
		while (true)
		{
			displayTaskToPerform();
			std::cin >> chooseFortask;
			if (chooseFortask == 1) // TO PUSH A VALUE
			{
				int value = 0;
				std::cout << "Enter Value to be pushed ->";
				std::cin >> value;
				obj.push(value);
			}
			if (chooseFortask == 2) // TO POP A VALUE
			{
				std::cout << "Poped value is ->" << obj.pop() << std::endl;
			}
			if (chooseFortask == 3) // DISPALY ARRAY
			{
				obj.display();
			}
			if (chooseFortask == 4) // GET TOP VALUE
			{
				std::cout << "Top value is ->" << obj.top() << std::endl;
			}
			if (chooseFortask == 5) // GET LENGTH
			{
				std::cout << "Length of the array is ->" << obj.getLength() << std::endl;
			}
			if (chooseFortask == 6) // EXIT
				break;
		}
	}
	if (chooseForDataType == 2) //FOR CHARACTER
	{
		MyStack<char> obj(size);
		while (true)
		{
			displayTaskToPerform();
			std::cin >> chooseFortask;
			if (chooseFortask == 1) // TO PUSH A VALUE
			{
				char value = '\0';
				std::cout << "Enter Value to be pushed ->";
				std::cin >> value;
				obj.push(value);
			}
			if (chooseFortask == 2) // TO POP A VALUE
			{
				std::cout << "Poped value is ->" << obj.pop() << std::endl;
			}
			if (chooseFortask == 3) // DISPALY ARRAY
			{
				obj.display();
			}
			if (chooseFortask == 4) // GET TOP VALUE
			{
				std::cout << "Top value is ->" << obj.top() << std::endl;
			}
			if (chooseFortask == 5) // GET LENGTH
			{
				std::cout << "Length of the array is ->" << obj.getLength() << std::endl;
			}
			if (chooseFortask == 6) // EXIT
				break;
		}
	}
	if (chooseForDataType == 3) // FOR STRING
	{
		MyStack<std::string> obj(size);
		while (true)
		{
			displayTaskToPerform();
			std::cin >> chooseFortask;
			if (chooseFortask == 1) // TO PUSH A VALUE
			{
				std::string value = "Garbage";
				std::cout << "Enter Value to be pushed ->";
				std::cin >> value;
				obj.push(value);
			}
			if (chooseFortask == 2) // TO POP A VALUE
			{
				std::cout << "Poped value is ->" << obj.pop() << std::endl;
			}
			if (chooseFortask == 3) // DISPALY ARRAY
			{
				obj.display();
			}
			if (chooseFortask == 4) // GET TOP VALUE
			{
				std::cout << "Top value is ->" << obj.top() << std::endl;
			}
			if (chooseFortask == 5) // GET LENGTH
			{
				std::cout << "Length of the array is ->" << obj.getLength() << std::endl;
			}
			if (chooseFortask == 6) // EXIT
				break;
		}
	}
	if (chooseForDataType == 4) // FOR DOUBLE
	{
		MyStack<double> obj(size);
		while (true)
		{
			displayTaskToPerform();
			std::cin >> chooseFortask;
			if (chooseFortask == 1) // TO PUSH A VALUE
			{
				double value = '\0';
				std::cout << "Enter Value to be pushed ->";
				std::cin >> value;
				obj.push(value);
			}
			if (chooseFortask == 2) // TO POP A VALUE
			{
				std::cout << "Poped value is ->" << obj.pop() << std::endl;
			}
			if (chooseFortask == 3) // DISPALY ARRAY
			{
				obj.display();
			}
			if (chooseFortask == 4) // GET TOP VALUE
			{
				std::cout << "Top value is ->" << obj.top() << std::endl;
			}
			if (chooseFortask == 5) // GET LENGTH
			{
				std::cout << "Length of the array is ->" << obj.getLength() << std::endl;
			}
			if (chooseFortask == 6) // EXIT
				break;
		}
	}
	if (chooseForDataType == 5) // TO EXIT
		std::cout << "THE END" << std::endl;
	return 0;
}
void displayDataTypeOption()
{
	std::cout << "----------------" << std::endl;
	std::cout << "1. FOR INTEGER" << std::endl;
	std::cout << "2. FOR CHARACTER" << std::endl;
	std::cout << "3. FOR STRING" << std::endl;
	std::cout << "4. FOR DOUBLE" << std::endl;
	std::cout << "5. TO EXIT" << std::endl;
	std::cout << "----------------" << std::endl;
}
void displayTaskToPerform()
{
	std::cout << "----------------" << std::endl;
	std::cout << "1. TO PUSH A VALUE" << std::endl;
	std::cout << "2. TO POP A VALUE" << std::endl;
	std::cout << "3. TO DISPLAY ARRAY" << std::endl;
	std::cout << "4. TO GET TOP VALUE" << std::endl;
	std::cout << "5. TO GET LENGTH" << std::endl;
	std::cout << "6. TO EXIT" << std::endl;
	std::cout << "----------------" << std::endl;
}