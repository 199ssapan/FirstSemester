#include "helpFuncs.h"

int main(int argc, char* argv[])
{
	char* string = argv[1];
	char* newString = putSpaces(string);
	int pairsCount = countLetters(string);
	char** numAndChars = StringToWords(newString);
	char** sides = allocMem2d(pairsCount, 2); 
	char** steps = allocMem2d(pairsCount, 10);
	int indexSide = 0, indexStep = 0;
	for (int i = 0; i < pairsCount * 2; i++)
	{
		if (i % 2 == 0)
		{
			strcpy(steps[indexStep], numAndChars[i]);
			indexStep++;
		}
		else
		{
			strcpy(sides[indexSide], numAndChars[i]);
			indexSide++;
		}
	}
	int sumsOfSteps[4] = { 0 };
	for (int i = 0; i < pairsCount; i++)
	{
		if (!strcmp("N", sides[i])) sumsOfSteps[0] += atoi(steps[i]);
		if (!strcmp("S", sides[i])) sumsOfSteps[1] += atoi(steps[i]);
		if (!strcmp("W", sides[i])) sumsOfSteps[2] += atoi(steps[i]);
		if (!strcmp("E", sides[i])) sumsOfSteps[3] += atoi(steps[i]);
	}
	exceptTwoSides(sumsOfSteps);
	printResult(sumsOfSteps);
	return 0;
}

