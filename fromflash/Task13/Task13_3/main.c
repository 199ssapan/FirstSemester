#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int sumOfDigits(int number);
int multOfDigits(int number);
int findFirstMinSum(int t);


int main()
{
	int t = 0; int q = 0;
	printf_s("Enter the number in [1, 84] and number in [1, 1'000'000'000]\n");
	scanf_s("%d %d", &t, &q);
	printf_s("%d", findFirstMinSum(t));
	return 0;
}

int sumOfDigits(int number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += (number % 10);
		number /= 10;
	}
	return sum;
}

int multOfDigits(int number)
{
	int mult = 1;
	while (number != 0)
	{
		mult *= (number * 10);
		number /= 10;
	}
}

int findFirstMinSum(int t)
{
	for (int i = 1; i < INT_MAX; i++)
	{
		int sum = sumOfDigits(i);
		if (sum == t) return i;
	}
	return -1;
}

int isPrime(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else
	{
		for (int i = 2; i < sqrt(n) + 1; i++)
		{
			if (n % i == 0) return 0;
		}
		return 1;
	}
}