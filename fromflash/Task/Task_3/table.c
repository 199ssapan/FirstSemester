#include <stdio.h>

int main()
{
	int row_count, column_count;
	char symb;

	printf_s("Enter the symbol\n>");
	scanf_s("%c", &symb);

	printf_s("Enter the number of rows\n>");
	scanf_s("%d", &row_count);

	printf_s("Enter the number of columns\n>");
	scanf_s("%d", &column_count);

	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < column_count; j++)
		{
			printf_s("%c ", symb);
		}
		printf_s("\n");
	}

}
