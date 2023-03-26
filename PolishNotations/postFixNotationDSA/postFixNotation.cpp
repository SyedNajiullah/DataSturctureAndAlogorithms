#include"Stack.h"

void displayMessage();
void display(const char * arr);
char *postFixNotation(char* arr);

int main()
{
	char arr[23] = { '(', '(', '(', 'A', '+', 'B', ')', '*', 'C', ')', '-', '(', '(', 'D', '+', 'E', ')', '/', 'F', ')', ')', '\0' }; // expression
	displayMessage();
	display(arr);
	char *brr = postFixNotation(arr);
	displayMessage();
	display(brr);
	return 0;
}

void displayMessage()
{
	std::cout << std::endl;
	std::cout << "\t----------------" << std::endl;
	std::cout << "\t--- ARRAY IS ---" << std::endl;
	std::cout << "\t----------------" << std::endl;
	std::cout << std::endl;
}

void display(const char * arr)
{
	if (arr == nullptr)
		std::cout << "arr = nullptr" << std::endl;
	else
	{
		std::cout << "  ";
		std::cout << arr <<std::endl;
	}
}

char * postFixNotation(char* arr)
{
	if (arr == nullptr)
		std::cout << "Cannot use postfix notation as the array is empty" << std::endl;
	Stack obj(100); // random max size
	char *brr = new char[50];
	int j = 0;
	char garbage = '\0';
	for (int i = 0; arr[i] != '\0'; ++i)
	{
		if (arr[i] == '(' || arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
		{
			obj.push(arr[i]);
		}
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
		{
			brr[j++] = arr[i];
		}
		if (arr[i] == ')')
		{
			brr[j++] = obj.pop();
			garbage = obj.pop();
		}
	}
	brr[j] = '\0';
	return brr;
}