#include <stdio.h>
#include <limits.h>

#define ELEMS_COUNT 5


int main()
{
	int arr[10];
	int number;
	printf_s("Enter a ten numbers\n");
	for (int i = 0; i < 10; i++)
	{
		printf_s("%d. ", i + 1);
		scanf_s("%d", &number);
		arr[i] = number;
	}
	int newArr[5];
	int max = INT_MIN;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int maxBuffer = INT_MIN;
	newArr[0] = max;
	for (int i = 1; i < ELEMS_COUNT; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] > maxBuffer && arr[j] < max)
			{
				maxBuffer = arr[j];
			}
		}
		max = maxBuffer;
		newArr[i] = maxBuffer;
		maxBuffer = INT_MIN;
	}
	
	int tmp;
	for (int i = 1; i < ELEMS_COUNT; i++)
	{
		for (int j = 1; j < ELEMS_COUNT; j++)
		{
			if (newArr[j] < newArr[j - 1])
			{
				tmp = newArr[j];
				newArr[j] = newArr[j - 1];
				newArr[j - 1] = tmp;
			}
		}
	}
	for (int i = 0; i < ELEMS_COUNT; i++)
	{
		printf_s("%d ", newArr[i]);
	}

	return 0;


}