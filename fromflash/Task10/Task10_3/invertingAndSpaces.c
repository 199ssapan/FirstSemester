#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define MAX_STRING_LEN 200
char* removeSpaces(char* string);
char* invertSymbols(char* string);
int countLinesInFile(FILE* file);
char** stringsFromFile(FILE* file, int linesCount);
void clearMemory2dArr(void** arr, int countOfLines);
void errex();

int main(int argc, char* argv[])
{
	FILE* inputFile;
	char* filename = argv[1];
	if (fopen_s(&inputFile, filename, "r"))
	{
		errex();
	}
	int linesCount = countLinesInFile(inputFile);
	char** stringsArr = stringsFromFile(inputFile, linesCount);
	for (int i = 0; i < linesCount; i++)
	{
		stringsArr[i] = invertSymbols(removeSpaces(stringsArr[i]));
	}
	fclose(inputFile);
	if (fopen_s(&inputFile, filename, "w"))
	{
		errex();
	}
	for (int i = 0; i < linesCount; i++)
	{
		fprintf_s(inputFile, "%s", stringsArr[i]);
	}
	clearMemory2dArr(stringsArr, linesCount);
	return 0;
}

char* removeSpaces(char* string)
{
	int len = strlen(string);
	if (len == 0)
	{
		return "";
	}
	char* stringToReturn = (char*)malloc(len * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		if (string[i] == '\t')
		{
			string[i] = ' ';
		}
	}
	int new_i = 0;
	bool flag = 0;
	for (int i = 0; i < len;i++)
	{
		if (string[i] != ' ')
		{
			stringToReturn[new_i] = string[i];
			new_i++;
			flag = 0;
		}
		else if (flag == 1){}
		else
		{
			stringToReturn[new_i] = string[i];
			new_i++;
			flag = 1;
		}
	}
	stringToReturn[new_i] = '\0';
	return stringToReturn;
}

char* invertSymbols(char* string)
{
	
	int len = strlen(string);
	char* buffer = (char*)malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			buffer[i] = (char)((int)(string[i]) + 32);
		}
		else if (string[i] >= 'a' && string[i] <= 'z')
		{
			buffer[i] = (char)((int)(string[i]) - 32);
		}
		else
		{
			buffer[i] = string[i];
		}
	}
	buffer[len] = '\0';
	return buffer;
}
void errex()
{
	perror("");
	exit(1);
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

char** stringsFromFile(FILE* file, int linesCount)
{
	fseek(file, 0, 0);
	char** text = (char**)malloc(linesCount * sizeof(char*));
	for (int i = 0; i < linesCount; i++)
	{
		text[i] = (char*)malloc((MAX_STRING_LEN + 1) * sizeof(char));
	}
	for (int i = 0; i < linesCount; i++)
	{
		fgets(text[i], MAX_STRING_LEN, file);
	}
	fseek(file, 0, 0);
	return text;
}
void clearMemory2dArr(void** arr, int countOfLines)
{
	for (int i = 0; i < countOfLines; i++)
	{
		free(arr[i]);
	}
	free(arr);
}