#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int sumDigitsInNumber(int num);
int A(int number);
int B(int number);


int main()
{
	int b = B(120);
	printf_s("%d", b);
	return 0;
}

int A(int number)
{
	int result = 0;
	int power = 1;
	while (number - sumDigitsInNumber(result) > 10)
	{
		result += 9 * power;
		power *= 10;
	}
	result += (number - sumDigitsInNumber(result)) * (power);
	return result;
}

int B(int number)
{
	if (number < 10 && number > 0) return number;
	if (isPrime(number)) return -1;
	int result = 0;
	int power = 1;
	for (int i = 9; i > 1; i--)
	{
		while (number % i == 0)
		{
			result += i * power;
			power *= 10;
			number /= i;
		}
	}
	return result;
}

int sumDigitsInNumber(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += (num % 10);
		num /= 10;
	}
	return sum;
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