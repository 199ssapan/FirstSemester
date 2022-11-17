#include "checking.h"

int isMatrix(FILE* file, char** filename)
{
	int linesCount = countLinesInFile(file);
	char** matrix = (char**)malloc(linesCount * sizeof(char*));
	for (int i = 0; i < linesCount; i++)
	{
		matrix[i] = (char*)malloc(MAX_STR_LEN * sizeof(char));
	}
	for (int i = 0; i < linesCount; i++)
	{
		matrix[i] = removeExtraSpaces(fgets(matrix[i], MAX_STR_LEN, file));
	}
	fclose(file);
	fopen_s(&file, filename, "w");
	for (int i = 0; i < linesCount; i++)
	{
		fprintf_s(file, "%s", matrix[i]);
	}
	fclose(file);
	fopen_s(file, filename, "r");
	int numInLine = countSymbols(matrix[0], ' ') + 1;
	for (int i = 0; i < linesCount; i++)
	{
		if (countSymbols(matrix[i], ' ') + 1 != numInLine)
		{
			return 1;
		}
	}
	return 0;
}

void errex()
{
	perror("");
	exit(1);
}

int isSymbols(FILE* file)
{
	fseek(file, 0, 0);
	int linesCount = countLinesInFile(file);
	char** matrix = (char**)malloc(linesCount * sizeof(char*));
	for (int i = 0; i < linesCount; i++)
	{
		matrix[i] = (char*)malloc(MAX_STR_LEN * sizeof(char));
	}
	for (int i = 0; i < linesCount; i++)
	{
		fgets(matrix[i], MAX_STR_LEN, file);
		for (int j = 0; j < strlen(matrix[i]); j++)
		{
			if (Ûmatrix[i][j] > '0' && matrix[i][j] < '0' || matrix[i][j] == '.' || matrix[i][j] == '-' || matrix[i][j]])
		}
	}
}