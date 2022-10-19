#include <stdio.h>

int main()
{
	printf_s("Enter a ten numbers and program will show positive numbers, you've entered\n");
	int numbers[10];
	int buffer;
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &buffer);
		numbers[i] = buffer;
	}
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] <= 0)
		{
			continue;
		}
		printf_s("%d ", numbers[i]);
	}
	return 0;
}