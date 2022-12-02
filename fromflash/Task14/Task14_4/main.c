#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* left, int* right);
void sorting(int* arr, int size);

int main(int argc, char* argv[])
{
	int countStringsToPrint = atoi(argv[1]);
	if (countStringsToPrint > argc - 2) return -1;
	int* lenArr = (int*)malloc(sizeof(int) * (argc - 2));
	for (int i = 2; i < argc; i++)
	{
		lenArr[i - 2] = strlen(argv[i]);
	}
	sorting(lenArr, argc - 2);
	int minSuitableLen = lenArr[countStringsToPrint - 1];
	int count = 0;
	for (int i = 2; i < argc; i++)
	{
		if (count == countStringsToPrint) break;
		if (strlen(argv[i]) >= minSuitableLen)
		{
			printf_s("%s ", argv[i]);
			count++;
		}
	}
	return 0;
}

void sorting(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] < arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
}

void swap(int* left, int* right)
{
	int tmp = *right;
	*right = *left;
	*left = tmp;
}