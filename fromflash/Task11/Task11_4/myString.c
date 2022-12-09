#include "myString.h"

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

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}