#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

unsigned sumDigitsInNumber(unsigned num);
unsigned A(int number);
unsigned B(int number);
unsigned C(int number);
unsigned D(unsigned number);
int isPrime(unsigned n);
unsigned isZero(unsigned number);
unsigned multDigitsInNumber(unsigned num);
void numbersFactros(int number);

int main()
{
	numbersFactros(84);
	return 0;
}

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

unsigned C(int number)
{
	int sum = 0;
	unsigned result = 0;
	long power = 100000000;
	if (number > 81)
	{
		if (number == 82) result += 1 * 10 * power;
		if (number == 83) result += 2 * 10 * power;
		if (number == 84) result += 3 * 10 * power;
	}
	while (number - sum >= 10)
	{
		result += 9 * power;
		power /= 10;
		sum = sumDigitsInNumber(result);
	}
	result += (number - sum) * power;
	return result;
}

unsigned isZero(unsigned number)
{
	while (number != 0)
	{
		if (number % 10 == 0)
		{
			return 0;
		}
		number /= 10;
	}
	return 1;
}

unsigned D(unsigned number)
{
	if (isPrime(number))
	{
		return -1;
	}
	for (unsigned i = UINT_MAX; i > 0; i--)
	{
		if (!isZero)
		{
			continue;
		}
		if (multDigitsInNumber(i) == number)
		{
			return i;
		}
	}
	return -1;
}

int isPrime(unsigned n)
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

void numbersFactros(int number)
{
	int div = 2;
	while (number != 1)
	{
		while (number % div == 0)
		{
			printf_s("%d ", div);
			number /= div;
		}
		div += 1;
	}
	printf_s("\n");
}

