#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_OF_FILENAME 101
int main(int argc, char* argv[])
{
	FILE* input;
	char* filename = argv[4];
	if (strlen(argv[4]) <= MAX_LEN_OF_FILENAME)
	{
		if (fopen_s(&input, argv[4], "r"))
		{
			perror("");
			exit(1);
		}
	}
	else
	{
		printf_s("Too long name of the file!");
		exit(1);
	}
	int linesCount = 1;
	char c;
	c = fgetc(input);
	while (c != EOF)
	{
		c = fgetc(input);
		if (c == '\n')
			linesCount++;
	}
	printf_s("%d points:\n", linesCount);

	int coefA = atoi(argv[1]);
	int coefB = atoi(argv[2]);
	int coefC = atoi(argv[3]);
	int** coordsArr = (int**)malloc(linesCount * sizeof(int*));
	for (int i = 0; i < linesCount; i++)
	{
		coordsArr[i] = (int*)malloc(2 * sizeof(int));
	}
	fseek(input, 0, 0);
	for (int i = 0; i < linesCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			fscanf_s(input, "%d ", &coordsArr[i][j]);
		}
	}
	int x, y;
	for (int i = 0; i < linesCount; i++)
	{
		x = *coordsArr[i];
		y = *(coordsArr[i] + 1);
		if ((coefA * x) + (coefB * y) + coefC == 0)
		{
			printf_s("%d %d: YES\n", x, y);
		}
		else
		{
			printf_s("%d %d: NO\n", x, y);
		}
	}
	for (int i = 0; i < linesCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			free(coordsArr[i][j]);
		}
	}
	free(coordsArr);
}