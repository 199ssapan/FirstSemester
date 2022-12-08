#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void fillIn0(int** arr);
void printField(int** arr);
int** createField();

int main()
{
	int** field = createField();
	int flag = 0;
	for (int i = 0; i < SIZE; i++)
	{
		printf_s("%d. Enter the position\n>", i + 1);
		int x = 0, y = 0;
		scanf_s("%d %d", &x, &y);
	if (field[x - 1][y - 1] == 1) flag = 1;
		for (int j = 0; j < SIZE; j++)
		{
			field[y - 1][j] = 1;
		}
		for (int j = 0; j < SIZE; j++)
		{
			field[j][x - 1] = 1;
		}
		int lx = x, ly = y;
		while (lx < SIZE && ly < SIZE)
		{
			field[ly][lx] = 1;
			lx++;
			ly++;
		}
		lx = x; ly = y;
		while (lx > -1 && ly < SIZE + 1)
		{
			field[ly - 1][lx - 1] = 1;
			lx--;
			ly++;
		}
		lx = x; ly = y;
		while (lx < SIZE + 1 && ly > -1)
		{
			field[ly - 1][lx - 1] = 1;
			lx++;
			ly--;
		}
		lx = x; ly = y;
		while (lx > -1 && ly > -1)
		{
			field[ly][lx] = 1;
			lx--;
			ly--;
		}
		printField(field);
	}
	flag == 1 ? printf_s("There is a pair of queens heating each other\n") : printf_s("There is no pair of queens heating each other\n");
	return 0;
}

void fillIn0(int** arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void printField(int** arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf_s("%d ", arr[i][j]);
		}
		printf_s("\n");
	}
}

int** createField()
{
	int** field = (int**)malloc(sizeof(int*) * SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		field[i] = (int*)malloc(sizeof(int) * SIZE);
	}
	fillIn0(field);
	return field;
}