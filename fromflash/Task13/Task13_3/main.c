#include "func.h"

int main()
{
	unsigned t = 0;
	for (unsigned i = 32; i > 0; i--)
	{
		setBit(&t, i);
	}
	printf_s("%u ", t);
	return 0;
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

//unsigned D(unsigned number)
//{
//	if (isPrime(number))
//	{
//		return -1;
//	}
//	for (unsigned i = UINT_MAX; i > 0; i--)
//	{
//		if (!isZero)
//		{
//			continue;
//		}
//		if (multDigitsInNumber(i) == number)
//		{
//			return i;
//		}
//	}
//	return -1;
//}

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
