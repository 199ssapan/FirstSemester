#include <stdio.h>

int main()
{
	printf_s("Enter an integer number\n>");
	int foo;
	scanf_s("%d", &foo);
	printf_s("Your number is %d.", foo);
	return 0;
}