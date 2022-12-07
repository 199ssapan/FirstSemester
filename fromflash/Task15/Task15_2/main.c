#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillIn(int* begin, int* end);
int* bubbleSort(int* begin, int* end);
int* merge(int* firstBegin, int* firstEnd, int* secondBegin, int* secondEnd);
/////////////////////////////////////////
void printArray(int* arr, int size);

int main(int argc, char* argv[])
{
	srand((unsigned)time(0));
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	int* arr1 = (int*)malloc(N * sizeof(int));
	int* arr2 = (int*)malloc(M * sizeof(int));
	fillIn(arr1, arr1 + N);
	fillIn(arr2, arr2 + M);
	printArray(arr2, M);
	printArray(arr1, N);
	arr1 = bubbleSort(arr1, arr1 + N);
	arr2 = bubbleSort(arr2, arr2 + M);
	printArray(arr1, N);
	printArray(arr2, M);
	int* newArr = merge(arr1, arr1 + N, arr2, arr2 + M);
	printArray(newArr, N + M);
	return 0;
}

void fillIn(int* begin, int* end)
{
	int* current = begin;
	while (current != end)
	{
		*current = rand() % 100;
		current++;
	}
}

int* bubbleSort(int* begin, int* end)
{
	int* current = begin;
	for (; current != end; current = (current + 1))
	{
		for (int* copyCurrent = begin; (copyCurrent + 1) != end; copyCurrent = (copyCurrent + 1))
		{
			if (*(copyCurrent + 1) < *copyCurrent)
			{
				int tmp = *copyCurrent;
				*copyCurrent = *(copyCurrent + 1);
				*(copyCurrent + 1) = tmp;
			}
		}
	}
	return begin;
}

int* merge(int* firstBegin, int* firstEnd, int* secondBegin, int* secondEnd)
{
	int sizeF = firstEnd - firstBegin;
	int sizeS = secondEnd - secondBegin;
	int* newArr = (int*)malloc(sizeof(int) * (sizeF + sizeS));
	int stepF = 0, stepS = 0;
	for (int i = 0; i < sizeF + sizeS; i++)
	{
		if (stepF < sizeF && stepS < sizeS)
		{
			if (*(firstBegin + stepF) < *(secondBegin + stepS))
			{
				newArr[i] = *(firstBegin + stepF);
				stepF++;
			}
			else
			{
				newArr[i] = *(secondBegin + stepS);
				stepS++;
			}
		}
		else if (stepF >= sizeF)
		{
			newArr[i] = *(secondBegin + stepS);
			stepS++;
		}
		else if (stepS >= sizeS)
		{
			newArr[i] = *(firstBegin + stepF);
			stepF++;
		}
	}
	return newArr;
}

////////////////////////////////////////////////////////////////////////////////////
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
}