#include <stdio.h>
int fibNum(int);
int main()
{
	printf_s("Enter the sequense number of number in fibonacci sequense\n>");
	int seqNum;
	scanf_s("%d", &seqNum);
	int number = fibNum(seqNum);
	printf_s("%d", number);
	return 0;
}
int fibNum(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		return fibNum(n - 1) + fibNum(n - 2);
	}
}