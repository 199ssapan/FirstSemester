#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getArrayOfDigits(unsigned number, unsigned* size);
void sort(int* arr, int size);
void swap(int* a, int* b);
int isSortedDiscending(int* arr, unsigned size);
int isSortedAscending(int* arr, unsigned size);
unsigned getMax(unsigned number);
unsigned getNumFromArr(int* arr, unsigned size);


int main()
{
	printf_s("%u ", getMax(2071));
	return 0;
}

int* getArrayOfDigits(unsigned number, unsigned* size)
{
	unsigned numberBackUp = number;
	unsigned count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	*size = count;
	int* digitsArr = (int*)malloc(sizeof(int) * count);
	number = numberBackUp;
	for (int i = count - 1; i >= 0; i--)
	{
		digitsArr[i] = number % 10;
		number /= 10;
	}
	return digitsArr;
}

unsigned getMax(unsigned number)
{
	unsigned size = 0;
	int* digitsArray = getArrayOfDigits(number, &size);
	if (size == 1) return 0;
	if (isSortedAscending(digitsArray, size)) return 0;
	if (isSortedDiscending(digitsArray, size))
	{
		swap(&digitsArray[size - 1], &digitsArray[size - 2]);
		return getNumFromArr(digitsArray, size);
	}
	else
	{
		int i;
		for (i = size - 1; i >= 0; i--)
		{
			if (digitsArray[i] > digitsArray[size - 1])
			{
				swap(&digitsArray[i], &digitsArray[size - 1]);
				break;
			}
		}
		for (int j = i + 1; j < size; j++)
		{
			for (int k = i + 1; k < size - 1; k++)
			{
				if (digitsArray[k] < digitsArray[k + 1]) swap(&digitsArray[k], &digitsArray[k + 1]);
			}
		}
		return getNumFromArr(digitsArray, size);
	}
}

int isSortedAscending(int* arr, unsigned size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return 0;
	}
	return 1;
}

int isSortedDiscending(int* arr, unsigned size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] < arr[i + 1]) return 0;
	}
	return 1;
}

unsigned getNumFromArr(int* arr, unsigned size)
{
	unsigned number = 0;
	unsigned power = 1;
	for (int i = 0; i < size - 1; i++)
	{
		power *= 10;
	}
	for (int i = 0; i < size; i++)
	{
		number += (power * arr[i]);
		power /= 10;
	}
	return number;
}

void sort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}