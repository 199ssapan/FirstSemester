#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100

char* concat(char* s1, char* s2);
char** StringToWords(char* string);
int countSymbols(char* string, char symbol);
char** decodeStringOfText(char* inputString);
int countLinesInFile(FILE* file);
char** TextToStrings(char*** textWords, FILE* file);
void errex(void);
char** lexGraphSorting(char** stringsOfText, int linesCount);

int main(int argc, char* argv[])
{
	FILE* input;
	char* filename = argv[1];
	if (fopen_s(&input, filename, "r"))
	{
		errex();
	}
	char* inputString = (char*)malloc(MAX_STRING_LEN * sizeof(char));
	if (!(inputString))
	{
		errex();
	}
	int linesCount = countLinesInFile(input);
	char*** wordsOfText = (char***)malloc((linesCount + 1) * sizeof(char**));
	if (!(wordsOfText))
	{
		errex();
	}
	for (int i = 0; i < linesCount + 1; i++)
	{
		fgets(inputString, MAX_STRING_LEN, input);
		wordsOfText[i] = decodeStringOfText(inputString);
	}
	fseek(input, 0, 0);
	char** stringsOfText = TextToStrings(wordsOfText, input);
	for (int i = 0; i < linesCount + 1; i++)
	{
		fgets(inputString, MAX_STRING_LEN, input);
		int wordsCount = countSymbols(inputString, ' ') + 1;
		for (int j = 0; j < wordsCount; j++)
		{
			free(wordsOfText[i][j]);
		}
	}
	free(inputString);
	fseek(input, 0, 0);
	lexGraphSorting(stringsOfText, linesCount);
	for (int i = 0; i < linesCount; i++)
	{
		printf_s("%s\n", stringsOfText[i]);
	}
	for (int i = 0; i < linesCount; i++)
	{
		free(stringsOfText[i]);
	}
	return 0;
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

char** decodeStringOfText(char* inputString)
{
	int wordsCount = countSymbols(inputString, ' ') + 1;
	char** words = StringToWords(inputString);
	for (int i = 0; i < wordsCount; i++)
	{
		for (int j = 0; j < strlen(words[i]) / 2; j++)
		{
			char tmp = words[i][j + strlen(words[i]) / 2];
			words[i][j + strlen(words[i]) / 2] = words[i][j];
			words[i][j] = tmp;
		}
	}
	return words;
}

int countLinesInFile(FILE* file)
{
	int linesCount = 1;
	char c;
	c = fgetc(file);
	while (c != EOF)
	{
		c = fgetc(file);
		if (c == '\n')
			linesCount++;
	}
	fseek(file, 0, 0);
	return linesCount;
}

char** TextToStrings(char*** textWords, FILE* file)
{
	char* bufferString = (char*)malloc(MAX_STRING_LEN * sizeof(char));
	int lines = countLinesInFile(file);
	char** textStrings = (char**)malloc(lines * sizeof(char*));
	if (!(textStrings))
	{
		errex();
	}
	for (int i = 0; i < lines; i++)
	{
		fgets(bufferString, MAX_STRING_LEN, file);
		textStrings[i] = (char*)malloc((strlen(bufferString) + 1) * sizeof(char));
		if (!(textStrings[i]))
		{
			errex();
		}
		int wordsCount = countSymbols(bufferString, ' ') + 1;
		textStrings[i] = "\0";
		for (int j = 0; j < wordsCount; j++)
		{
			textStrings[i] = concat(textStrings[i], textWords[i][j]);
			textStrings[i] = concat(textStrings[i], " ");
		}
		textStrings[i][strlen(textStrings[i]) - 2] = '\0';
	}
	fseek(file, 0, 0);
	return textStrings;
}

char* concat(char* firstString, char* secondString)
{
	int firstLength = strlen(firstString);
	int secondLength = strlen(secondString);
	char* result = malloc(strlen(firstString) + strlen(secondString) + 1);
	if (!(result))
	{
		errex();
	}
	memcpy(result, firstString, firstLength);
	memcpy(result + firstLength, secondString, secondLength + 1);

	return result;
}

void errex(void)
{
	perror("");
	exit(1);
}

char** lexGraphSorting(char** stringsOfText, int linesCount)
{
	for (int k = 0; k < linesCount - 1; k++)
	{
		for (int i = 0; i < linesCount - 1; i++)
		{
			for (int j = 0; j < min(strlen(stringsOfText[i]), strlen(stringsOfText[i + 1])); j++)
			{
				if (stringsOfText[i][j] != stringsOfText[i + 1][j])
				{
					if (stringsOfText[i][j] > stringsOfText[i + 1][j])
					{
						char* tmp = stringsOfText[i];
						stringsOfText[i] = stringsOfText[i + 1];
						stringsOfText[i + 1] = tmp;
					}
					break;
				}
			}
		}
	}
	return stringsOfText;
}