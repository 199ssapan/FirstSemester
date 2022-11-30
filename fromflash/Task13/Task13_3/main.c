#include "func.h"

int main()
{
	unsigned T = 38;
	unsigned Q = 10;
	unsigned a = A(T);
	printf_s("%u\n", a);
	unsigned b = B(Q);
	b != 0 ? printf_s("%u\n", b) : printf_s("Doesn't exist!\n");
	unsigned c = C(T);
	printf_s("%u\n", c);
	unsigned d = D(Q);
	d != 0 ? printf_s("%u\n", d) : printf_s("Doesn't exist!\n");
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