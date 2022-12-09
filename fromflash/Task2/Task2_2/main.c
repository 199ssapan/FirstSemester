#include <stdio.h>

int main()
{
	printf_s("Enter your number\n>");
	int number;
	scanf_s("%d", &number);
	if (number % 2 == 0)
	{
		for (int i = 1; i <= number; i++)
		{
			printf("%d ", i);
		}
	}
	else
	{
		for (int i = number; i >= 1; i--)
		{
			printf("%d ", i);
		}
	}
	return 0;
}