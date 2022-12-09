#include <stdio.h>

int main()
{
	int elem_count;
	printf_s("Enter the count of elements in wall\n>");
	scanf_s("%d", &elem_count);
	for (int i = 0; i < elem_count; i++)
	{
		printf_s(" _  ");
	}
	printf_s("\n");
	for (int i = 0; i < elem_count - 1; i++)
	{
		for (int j = 0; j < elem_count - 1; j++)
		{
			printf_s("/ \\_");
		}
		printf_s("/ \\");
		printf_s("\n");
		for (int j = 0; j < elem_count - 1; j++)
		{
			printf("\\_/ ");
		}
		printf_s("\\_/");
		printf_s("\n");
	}

}