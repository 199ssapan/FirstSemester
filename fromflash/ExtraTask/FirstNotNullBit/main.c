#include <stdio.h>
#include <math.h>
#include <limits.h>

unsigned long long getNumWithoutFirstNotNullBit(unsigned long long number);
unsigned getPositionOfFirstNotNullBit(unsigned long long number);
unsigned badImplementation(unsigned long long number);



int main()
{
	
	printf_s("%d: %u\n", 0, getPositionOfFirstNotNullBit(0));
	printf_s("%d: %u\n", 24, getPositionOfFirstNotNullBit(24));
	printf_s("%d: %u\n", 1111110, getPositionOfFirstNotNullBit(1111110));
	printf_s("%d: %u\n", 16000, getPositionOfFirstNotNullBit(16000));
	printf_s("%d: %u\n", 1024, getPositionOfFirstNotNullBit(1024));
	printf_s("%d: %u\n", 1, getPositionOfFirstNotNullBit(1));
	printf_s("%d: %u\n", 2, getPositionOfFirstNotNullBit(2));
	printf_s("%d: %u\n", 8, getPositionOfFirstNotNullBit(8));
	printf_s("%d: %u\n", 542, getPositionOfFirstNotNullBit(542));
	printf_s("%d: %u\n", 712960, getPositionOfFirstNotNullBit(712960));
	printf_s("%d: %u\n", 1024, badImplementation(1024));
	return 0;
}

unsigned long long getNumWithoutFirstNotNullBit(unsigned long long number)
{
	return number & (number - 1);
}

unsigned getPositionOfFirstNotNullBit(unsigned long long number)
{
	if (number == 0) return 0;
	unsigned long long numWOFirstNNBit = getNumWithoutFirstNotNullBit(number);
	unsigned degreeOf2 = number ^ numWOFirstNNBit;
	return (unsigned)log2(degreeOf2) + 1;
}

unsigned badImplementation(unsigned long long number)
{
	if (number == 0) return 0;
	for (unsigned i = 1; i <= ULLONG_MAX; (i <<= 1))
	{
		if ((i & number) != 0) return (unsigned)log2(i) + 1;
	}
	return 0;
}