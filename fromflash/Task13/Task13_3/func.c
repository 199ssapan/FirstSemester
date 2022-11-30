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

unsigned B(unsigned number)
{
	if (!isPrime(number)) return 0;
	for (unsigned i = 1; i < UINT_MAX; i++)
	{
		if (multDigitsInNumber(i) == number)
		{
			return i;
		}
	}
}

unsigned C(unsigned number)
{
	for (unsigned i = UINT_MAX; i > 0; i--)
	{
		if (sumDigitsInNumber(i) == number)
		{
			return i;
		}
	}
}

unsigned D(unsigned number)
{
	if (!isPrime(number)) return 0;
	for (unsigned i = UINT_MAX; i > 0; i--)
	{
		if (multDigitsInNumber(i) == number)
		{
			return i;
		}
	}
	return 0;
}

int isPrime(unsigned n)
{
	if (n == 1)
	{
		return 0;
	}
	for (unsigned i = 2; i < sqrt(n) + 1; i++)
	{
		if (n % i == 0) return 1;
	}
	return 0;
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
	int mult = 1;
	while (num != 0)
	{
		mult *= (num % 10);
		num /= 10;
	}
	return mult;
}