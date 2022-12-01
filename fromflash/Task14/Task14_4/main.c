#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* getMaxLenIndexes(int* arr, int size);
int* copyIntArr(int* arrSrc, int size);
void swap(int* a, int* b);
int isElemInArr(int* arr, int size, int value);
void sort(int* arr, int size);

int main(int argc, char* argv[])
{
	int count = atoi(argv[1]);
	if (count > argc - 2) return 1;
	int* lenArr = (int*)malloc(sizeof(int) * (argc - 2));

	for (int i = 2; i < argc; i++)
	{
		lenArr[i - 2] = strlen(argv[i]);
	}

	int* lenArrCopy = copyIntArr(lenArr, argc - 2);

	int* maxIndexes = getMaxLenIndexes(lenArrCopy, argc - 2);
	sort(maxIndexes, count);
	for (int i = 0; i < count; i++)
	{
		printf_s("%s ", argv[maxIndexes[i] + 2]);
	}
	return 0;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int* getMaxLenIndexes(int* arr, int size)
{
	int* indexArr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		indexArr[i] = i;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] < arr[i + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swap(&indexArr[j], &indexArr[j + 1]);
			}
		}
	}
	return indexArr;
}

int* copyIntArr(int* arrSrc, int size)
{
	int* arrDest = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		arrDest[i] = arrSrc[i];
	}
	return arrDest;
}

int isElemInArr(int* arr, int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value) return 1;
	}
	return 0;
}

void sort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
}