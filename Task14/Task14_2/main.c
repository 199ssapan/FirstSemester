#include <stdio.h>
#include <stdlib.h>

int* getArrayOfDigits(unsigned number, int* size);


int main()
{
	unsigned N;
	scanf_s("%u", &N);
	int size = 0;
	int* arr = getArrayOfDigits(N, &size);
	for (int i = 0; i < size; i++)
	{
		printf_s("%d ", arr[i]);
	}
	return 0;
}

int* getArrayOfDigits(unsigned number, int* size)
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