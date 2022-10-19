#include <stdio.h>

int main()
{
	int number;
	printf_s("Enter your number\n>");
	scanf_s("%d", &number);
	do
	{
		if (number % 2 == 0)
		{
			printf("This number is Even\n>");
		}
		else
		{
			printf("This number is Odd\n>");
		}
		scanf_s("%d", &number);
	} while (number != 0);
}
