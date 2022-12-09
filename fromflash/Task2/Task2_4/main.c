#include <stdio.h>

int main()
{
	int i, N, sum;

	printf("Enter your number\n>");
	scanf_s("%d", &N);

	while (N > 0)
	{
		Sleep(100);
		i = 1;
		sum = 0;
		while (sum < N)
		{
			Sleep(50);
			printf_s("%d ", i);
			i++;
			sum += i;
		}
		printf("\n");
		N /= 2;
	}
	return 0;
}