#include "checking.h"
#include "mainMenu.h"
#include "matrix.h"

int isMatrix(FILE* file, char* filename)
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
	free(matrix);
	return 0;
}

void errex(char* text)
{
	text == 0 ? perror("") : printf_s("%s", text);
	exit(1);
}

int isExcessSymbols(FILE* file)
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
			if (!((matrix[i][j] >= '0' && matrix[i][j] <= '9') || matrix[i][j] == '-' || matrix[i][j] == '.' || matrix[i][j] == ' ' || matrix[i][j] == '\n'))
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < linesCount; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}

int isBigNumber(FILE* file)
{
	fseek(file, 0, 0);
	int linesCount = countLinesInFile(file);
	for (int i = 0; i < linesCount; i++)
	{
		char* buffer = (char*)malloc(MAX_STR_LEN * sizeof(char));
		if (checkStringToWords(fgets(buffer, MAX_STR_LEN, file)))
		{
			return 1;
		}
	}
	fseek(file, 0, 0);
	return 0;
}

int checkStringToWords(char* string)
{
	int spaceCount = countSymbols(string, ' ');
	int* spaceIndexArr = (int*)calloc((spaceCount + 2), sizeof(int));
	if (!(spaceIndexArr))
	{
		errex("");
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
		errex("");
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
			errex("");
		}
		strncpy(wordsArr[i], string + spaceIndexArr[i] + 1, lettersCount);
		wordsArr[i][lettersCount] = '\0';
	}
	for (int i = 0; i < wordsCount; i++)
	{
		if (strlen(wordsArr[i]) > 20)
		{
			return 1;
		}
	}
	free(spaceIndexArr);
	for (int i = 0; i < wordsCount; i++)
	{
		free(wordsArr[i]);
	}
	free(wordsArr);
	return 0;

}

void checkFile(FILE* file, char* filename)
{
	char c = fgetc(file);
	if (c == ' ' || c == '\n' || c == '\t') errex("Wrong data!");
	if (c == EOF) errex("No data!");
	fseek(file, 0, 0);
	if (isMatrix(file, filename)) errex("Please enter the matrix correctly and delete excess symbols\n");
	if (isExcessSymbols(file)) errex("Excess symbols in the file!");
	if (isBigNumber(file)) errex("Too big number in the file!");
}

void useCurrentMatrix(Matrix* matrix, Matrix** matrices)
{
	printf_s("Do you want to use this matrix for future calculations?\n1. Yes\n2. No\n");
	char action = _getch();
	switch (action)
	{
	case '1':
		printf_s("Instead of what matrix do you want to use this matrix??\n1. 1\n2. 2\n");
		char f = _getch();
		switch (f)
		{
		case '1':
			copyData(matrix, matrices[0]);
			break;
		case '2':
			copyData(matrix, matrices[1]);
			break;
		}
	case 2:
		break;
	default:
		break;
	}
}
void writeToFile(Matrix* matrix, FILE* file, char* filename)
{
	fclose(file);
	if (fopen_s(&file, filename, "w")) errex("");
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			j == matrix->columns - 1 ? fprintf_s(file, "%lf", matrix->data[i][j]) : fprintf_s(file, "%lf ", matrix->data[i][j]);
		}
		if (i != matrix->rows - 1)
		{
			fprintf_s(file, "\n");
		}
	}
	fclose(file);
	if (fopen_s(&file, filename, "r")) errex("");
}

int countLinesInFile(FILE* file)
{
	fseek(file, 0, 0);
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

char* removeExtraSpaces(char* string)
{
	int len = strlen(string);
	if (len == 0) return "";
	char* stringToReturn = (char*)malloc(len * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		string[i] = string[i] == '\t' ? ' ' : string[i];
	}
	int new_i = 0;
	int flag = 0;
	for (int i = 0; i < len;i++)
	{
		if (string[i] != ' ')
		{
			stringToReturn[new_i] = string[i];
			new_i++;
			flag = 0;
		}
		else if (flag == 1) {}
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

void rewritingToFile(FILE* file, char* filename, int linesCount)
{
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
	fopen_s(file, filename, "w");
	for (int i = 0; i < linesCount; i++)
	{
		fprintf_s(file, "%s", matrix[i]);
	}
	for (int i = 0; i < linesCount; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return;
}

void copyData(Matrix* matrixFrom, Matrix* matrixTo)
{
	if (matrixTo != NULL)
	{
		freeMatrix(matrixTo);
	}
	allocMatrix(matrixTo, matrixFrom->rows, matrixFrom->columns);
	for (int i = 0; i < matrixFrom->rows; i++)
	{
		for (int j = 0; j < matrixFrom->columns; j++)
		{
			matrixTo->data[i][j] = matrixFrom->data[i][j];
		}
	}
	matrixTo->det = matrixFrom->det;
	matrixTo->hasDet = matrixFrom->hasDet;
}

void detCheck(Matrix* matrix)
{
	if (matrix->hasDet != 0)
	{
		printf_s("Determinant is:\t%lf\n", matrix->det);
		system("pause");
	}
	else
	{
		if (getDeterminant(matrix))
		{
			if (matrix->hasDet == 1)
			{
				printf_s("Determinant is:\t%lf\n", matrix->det);
				system("pause");
			}
			else
			{
				printf_s("This matrix has no determinant!\n");
				system("pause");
			}
		}
	}
}
