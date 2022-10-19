#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	srand((unsigned)time(0));
	printf_s("Enter A\n");
	int A;
	scanf_s("%d", &A);
	printf_s("Enter B, B must be smaller than A\n");
	int B;
	scanf_s("%d", &B);
	int* arrA = (int*)malloc(A * sizeof(int));
	int* arrB = (int*)malloc(B * sizeof(int));
	for (int i = 0; i < A; i++)
	{
		arrA[i] = (rand() % 21 + 10) * (rand() % 2 ? 1 : -1);
	}
	int tmp;
	int randIndex;
	for (int i = 0; i < B; i++)
	{
		randIndex = rand() % (A - i);
		arrB[i] = arrA[randIndex];
		tmp = arrA[randIndex];
		arrA[randIndex] = arrA[A - i - 1];
		arrA[A - i - 1] = tmp;

	}
	free(arrA);
	for (int i = 0; i < B; i++)
	{
		printf_s("%d ", arrB[i]);
	}
	free(arrB);
	return 0;
}