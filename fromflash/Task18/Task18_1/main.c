#include <stdio.h>
#include <stdlib.h>

int** alloc2DArr(int rows, int columns);
void fillInWithZeros(int** arr, int rows, int columns);
void searchZeroAndChange(int** arr, int rows, int columns, int value);
void printArray(int** arr, int rows, int columns);
void fillInFrame(int** arr, int rows, int columns, int* value);



int main()
{
    int rows = 0;
    int columns = 0;
    int value = 1;
    printf_s("Enter the row count\n>");
    scanf_s("%d", &rows);
    printf_s("Enter the columns count\n>");
    scanf_s("%d", &columns);
    int** arr = alloc2DArr(rows, columns);
    fillInWithZeros(arr, rows, columns);
    fillInFrame(arr, rows, columns, &value);
    int y = 1;
    int x = 1;
    int finalValueResult = rows * columns;

    while (value < finalValueResult)
    {
        while (arr[y][x + 1] == 0)
        {
            arr[y][x] = value;
            value++;
            x++;
        }
        while (arr[y + 1][x] == 0)
        {
            arr[y][x] = value;
            value++;
            y++;
        }
        while (arr[y][x - 1] == 0)
        {
            arr[y][x] = value;
            value++;
            x--;
        }
        while (arr[y - 1][x] == 0)
        {
            arr[y][x] = value;
            value++;
            y--;
        }
    }
    searchZeroAndChange(arr, rows, columns, value);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf_s("%d\t", arr[i][j]);
        }
        printf_s("\n");
    }
	return 0;
}


int** alloc2DArr(int rows, int columns)
{
    int** arr = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * columns);
    }
    return arr;
}

void fillInWithZeros(int** arr, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void searchZeroAndChange(int** arr, int rows, int columns, int value)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = value;
                return;
            }
        }
    }
}

void printArray(int** arr, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf_s("%d\t", arr[i][j]);
        }
        printf_s("\n");
    }
}

void fillInFrame(int** arr, int rows, int columns, int* value)
{
    for (int i = 0; i < columns; i++) 
    {
        arr[0][i] = *value;
        (*value)++;
    }
    for (int i = 1; i < rows; i++) 
    {
        arr[i][columns - 1] = *value;
        (*value)++;
    }
    for (int i = columns - 2; i >= 0; i--) 
    {
        arr[rows - 1][i] = *value;
        (*value)++;
    }
    for (int i = rows - 2; i > 0; i--) 
    {
        arr[i][0] = *value;
        (*value)++;
    }
}