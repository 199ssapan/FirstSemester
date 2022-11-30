#include <stdio.h>

int getCrackCount(int a, int b);
int improvedGetCrackCount(int a, int b);

int main()
{
	printf_s("%d ", improvedGetCrackCount(5, 7));
	printf_s("%d ", getCrackCount(5, 7));
	return 0;
}

int getCrackCount(int a, int b)
{
	int min, max;
	if (a < b)
	{
		min = a;
		max = b;
	}
	else if (a >= b)
	{
		max = a;
		min = b;
	}
	return max - 1 + max * (min - 1);
}

int improvedGetCrackCount(int a, int b)
{
	if (a == 1 && b == 1) return 0;
	return a - 1 + a * (b - 1);
}