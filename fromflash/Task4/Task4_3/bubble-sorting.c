#include <stdio.h>
#include <limits.h>

#define COUNTELEM 5


int main()
{
	int intArray[10];
	int number;
	printf_s("Enter a ten numbers\n");
	for (int i = 0; i < 10; i++)
	{
		printf_s("%d. ", i + 1);
		scanf_s("%d", &number);
		intArray[i] = number;
	}
	int newIntArray[5];
	int max = INT_MIN;
	for (int i = 0; i < 10; i++)
	{
		if (intArray[i] > max)
		{
			max = intArray[i];
		}
	}
	int maxBuffer = INT_MIN;
	newIntArray[0] = max;
	for (int i = 1; i < COUNTELEM; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (intArray[j] > maxBuffer && intArray[j] < max)
			{
				maxBuffer = intArray[j];
			}
		}
		max = maxBuffer;
		newIntArray[i] = maxBuffer;
		maxBuffer = INT_MIN;
	}
	
	int bubble;
	for (int i = 1; i < COUNTELEM; i++)
	{
		for (int j = 1; j < COUNTELEM; j++)
		{
			if (newIntArray[j] < newIntArray[j - 1])
			{
				bubble = newIntArray[j];
				newIntArray[j] = newIntArray[j - 1];
				newIntArray[j - 1] = bubble;
			}
		}
	}
	for (int i = 0; i < COUNTELEM; i++)
	{
		printf_s("%d ", newIntArray[i]);
	}

	return 0;


}