#include "func.h"

unsigned A(int number)
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

unsigned B(int number)
{
	if (number < 10 && number > 0) return number;
	if (isPrime(number)) return 0;
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

unsigned C(unsigned number)
{
	if (number <= 57)
	{
		int sum = 0;
		int uintmax[] = { 4, 2, 9, 4, 9, 6, 7, 2, 9, 5 };
		int maxNum[10] = { 0 };
		int i;
		for (i = 0; i < 10; i++)
		{
			if (sum < number)
			{
				sum += uintmax[i];
				maxNum[i] = uintmax[i];
			}

		}
	}
}

void setBit(unsigned* number, unsigned shift)
{
	*number = *number | (1 << shift);
}

unsigned sumDigitsInNumber(unsigned num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

unsigned multDigitsInNumber(unsigned num)
{
	int mult = 0;
	while (num != 0)
	{
		mult *= (num % 10);
		num /= 10;
	}
	return mult;
}
