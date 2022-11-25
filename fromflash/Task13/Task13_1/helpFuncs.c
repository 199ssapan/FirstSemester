#include "helpFuncs.h"

char** allocMem2d(int d1, int d2)
{
	char** charArr = (char**)malloc(sizeof(char*) * d1);
	for (int i = 0; i < d1; i++)
	{
		charArr[i] = (char*)malloc(sizeof(char) * d2);
	}
	return charArr;
}
int countLetters(char* string)
{
	int count = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z')
		{
			count++;
		}
	}
	return count;
}

char* putSpaces(char* string)
{
	int count = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == 'S' || string[i] == 'N' || string[i] == 'W' || string[i] == 'E')
		{
			count++;
		}
	}
	count *= 2;
	char* newString = (char*)malloc(sizeof(char) * (strlen(string) + count + 1));
	int new_i = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (i == strlen(string) - 1)
		{
			newString[new_i] = ' ';
			new_i++;
			newString[new_i] = string[i];
			new_i++;
		}
		else if (string[i] == 'S' || string[i] == 'N' || string[i] == 'W' || string[i] == 'E')
		{
			newString[new_i] = ' ';
			new_i++;
			newString[new_i] = string[i];
			new_i++;
			newString[new_i] = ' ';
			new_i++;
		}
		else
		{
			newString[new_i] = string[i];
			new_i++;
		}
	}
	newString[strlen(string) + count - 1] = '\0';
	return newString;
}
char** StringToWords(char* string)
{
	int spaceCount = countSymbols(string, ' ');
	int* spaceIndexArr = (int*)calloc((spaceCount + 2), sizeof(int));
	if (!(spaceIndexArr))
	{
		errex();
	}
	spaceIndexArr[0] = -1;
	spaceIndexArr[spaceCount + 1] = strlen(string);
	int new_i = 1;
	for (int i = 1; i < strlen(string); i++)
	{
		if (string[i] == ' ')
		{
			spaceIndexArr[new_i] = i;
			new_i++;
		}
	}
	int wordsCount = spaceCount + 1;
	char** wordsArr = (char**)malloc(wordsCount * sizeof(char*));
	if (!(wordsArr))
	{
		errex();
	}
	for (int i = 0; i < wordsCount; i++)
	{
		int lettersCount = spaceIndexArr[i + 1] - spaceIndexArr[i] - 1;
		wordsArr[i] = (char*)malloc((lettersCount + 1) * sizeof(char));
		if (!(wordsArr[i]))
		{
			for (int j = 0; j < i; j++)
			{
				free(wordsArr[j]);
			}
			break;
			errex();
		}
		strncpy(wordsArr[i], string + spaceIndexArr[i] + 1, lettersCount);
		wordsArr[i][lettersCount] = '\0';
	}
	return wordsArr;
}

void errex(void)
{
	perror("");
	exit(1);
}

int countSymbols(char* string, char symbol)
{
	int countSymb = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == symbol)
		{
			countSymb++;
		}
	}
	return countSymb;

}

void printResult(int sumsOfSteps[4])
{
	if (sumsOfSteps[0] != 0) printf_s("%d%s", sumsOfSteps[0], "N");
	if (sumsOfSteps[1] != 0) printf_s("%d%s", sumsOfSteps[1], "S");
	if (sumsOfSteps[2] != 0) printf_s("%d%s", sumsOfSteps[2], "W");
	if (sumsOfSteps[3] != 0) printf_s("%d%s", sumsOfSteps[3], "E");
}

void exceptTwoSides(int sumsOfSteps[4])
{
	int minNS = min(sumsOfSteps[0], sumsOfSteps[1]);
	sumsOfSteps[0] -= minNS;
	sumsOfSteps[1] -= minNS;
	int minEW = min(sumsOfSteps[2], sumsOfSteps[3]);
	sumsOfSteps[2] -= minEW;
	sumsOfSteps[3] -= minEW;
}