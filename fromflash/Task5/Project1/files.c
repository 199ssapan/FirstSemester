#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 3
void sorting(int arr[SIDES]);
int howMuchToAdd(int arr[SIDES]);
int main()
{
	srand((unsigned)time(0));
	FILE* input, * result;
	if (fopen_s(&input, "input.txt", "w") || fopen_s(&result, "result.txt", "w"))
	{
		exit(1);
	}
	int num;
	for (int i = 0; i < SIDES; i++)
	{
		num = rand() % 100;
		fprintf_s(input, "%d ", num);
	}
	fclose(input);
	if (fopen_s(&input, "input.txt", "r"))
	{
		exit(1);
	}
	int arr[SIDES];
	int tmp;
	for (int i = 0; i < SIDES; i++)
	{
		fscanf_s(input, "%d ", &tmp);
		arr[i] = tmp;
	}
	int res = howMuchToAdd(arr);
	fprintf_s(result, "%d ", res);

	return 0;
}
void sorting(int arr[SIDES])
{
	int buffer;
	for (int i = 0; i < SIDES; i++)
	{
		for (int j = 1; j < SIDES; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				buffer = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = buffer;
			}
		}
	}
}
int howMuchToAdd(int arr[SIDES])
{
	sorting(arr);
	int difference;
	if (arr[0] + arr[1] <= arr[2])
	{
		difference = arr[2] - (arr[0] + arr[1]) + 1;
	}
	else
	{
		difference = 0;
	}
	return;
}