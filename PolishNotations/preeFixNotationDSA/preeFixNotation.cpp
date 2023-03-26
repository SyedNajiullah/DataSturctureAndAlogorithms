#include"Stack.h"

void diplayArray(const char *arr);
void displayMessge();
char *preeFixNotation(const char * arr);
int calSize(const char * arr);
char * reverseArray(const char * arr);

int main()
{
	char arr[23] = "(((A+B)*C)-((D+E)/F))\0";
	displayMessge();
	diplayArray(arr);
	char * brr = preeFixNotation(arr);
	displayMessge();
	std::cout << "::: PREE FIX NOTATION IS :::" << std::endl;
	diplayArray(brr);
	return 0;
}

char * reverseArray(const char * arr)
{
	int size = calSize(arr);
	int j = size;
	char *reverseArray = new char[size];
	for (int i = 0; arr[i] != '\0'; ++i)
		reverseArray[i] = arr[--j];
	reverseArray[size] = '\0';
	return reverseArray;
}

int calSize(const char * arr)
{
	int size = 0;
	for (int i = 0; arr[i] != '\0'; i++)
		size++;
	return size;
}

char *preeFixNotation(const char * arr)
{
	Stack obj(50);
	int size = 0;
	int j = 0;
	char bracket = '\0';
	size = calSize(arr);
	char * brr = new char[size];
	for (int i = size; i >= 0; i--)
	{
		if (arr[i] == ')' || arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
		{
			obj.push(arr[i]);
		}
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
		{
			brr[j++] = arr[i];
		}
		if (arr[i] == '(')
		{
			brr[j++] = obj.pop();
			bracket = obj.pop();
		}
	}
	brr[j] = '\0';
	char * temp = reverseArray(brr);
	delete[]brr;
	brr = nullptr;
	return temp;
}

void displayMessge()
{
	std::cout << "\t\t--- ***** ---" << std::endl;
	std::cout << "\t\t--- ARRAY ---" << std::endl;
	std::cout << "\t\t--- ***** ---" << std::endl;
	std::cout << std::endl;
}

void diplayArray(const char *arr)
{
	std::cout << std::endl;
	std::cout << arr << std::endl;
	std::cout << std::endl;
}