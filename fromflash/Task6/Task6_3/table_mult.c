#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 10
#define ROWS 10

int main()
{
	int table[ROWS][COLUMNS];
	int multiplier = 1;
	int number = 1;
	int elem;
	int new_i = 0, new_j = 0;
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		if (i % (COLUMNS) == 0 && i != 0)
		{
			multiplier = 1;
			number++;
		}
		elem = number * multiplier;
		multiplier++;
		if (i % COLUMNS == 0 && i != 0)
		{
			new_i++;
			new_j = 0;
		}
		table[new_i][new_j] = elem;
		new_j++;
	}
	new_i = 0;
	new_j = 0;
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		if (i % COLUMNS == 0 && i != 0)
		{
			new_i++;
			new_j = 0;
			printf_s("\n");
		}
		printf_s("%d ", table[new_i][new_j]);
		new_j++;
	}
	return 0;
}