#include <stdio.h>

int main()
{
	char charArray[] = { 'a', 'b', 'c', 'd' };
	int intArray[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(charArray) / sizeof(char); i++)
	{
		printf_s("%c ", charArray[i]);
	}
	printf("\n");
	for (int i = 0; i < sizeof(intArray) / sizeof(int); i++)
	{
		printf_s("%d ", intArray[i]);
	}
	return 0;
}