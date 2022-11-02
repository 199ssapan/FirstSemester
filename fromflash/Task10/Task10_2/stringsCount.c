#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 200

int countLinesInFile(FILE* file);
void errex();
void clearMemory2dArr(void** arr, int countOfLines);
char** stringsFromFile(FILE* file, int linesCount);

int main(int argc, char* argv[])
{
	FILE* inputFile;
	char* filename = argv[1];
	if (fopen_s(&inputFile, filename, "r"))
	{
		errex();
	}
	int linesCount = countLinesInFile(inputFile);
	char** text = stringsFromFile(inputFile, linesCount);
	fclose(inputFile);
	if (fopen_s(&inputFile, filename, "w"))
	{
		errex();
	}
	fprintf_s(inputFile, "%d\n", linesCount + 1);
	for (int i = 0; i < linesCount; i++)
	{
		fprintf_s(inputFile, "%s", text[i]);
	}
	fclose(inputFile);
	clearMemory2dArr(text, linesCount);
	return 0;
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
	printf_s("OK");
	return linesCount;
}

void errex()
{
	perror("");
	exit(1);
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