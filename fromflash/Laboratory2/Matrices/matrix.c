#include "matrix.h"
#include "mainMenu.h"
#include "checking.h"

void handWriteMatrix(double** matrix, int rowCount, int columnCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			scanf_s("%lf", &matrix[i][j]);
		}
	}
}
double** multiplyMatrices(double** firstMatrix, int rowCountFirst, int columnCountFirst, double** secondMatrix, int rowCountSecond, int columnCountSecond)
{
	if (columnCountFirst != rowCountSecond)
	{
		printf_s("Wrong size of matrix!\n");
		return NULL;
	}
	double** newMatrix = allocMatrix(rowCountFirst, columnCountSecond);
	for (int i = 0; i < rowCountFirst; i++)
	{
		for (int j = 0; j < columnCountSecond; j++)
		{
			double sum = 0.0;
			for (int k = 0; k < columnCountFirst; k++)
			{
				sum += (firstMatrix[i][k] * secondMatrix[k][j]);
			}
			newMatrix[i][j] = sum;
		}
	}
	return newMatrix;
}

double** transpose(double** matrixToTranspose, int rowCount, int columnCount)
{
	int newMatrixRows = columnCount;
	int newMatrixColumns = rowCount;
	double** newMatrix = allocMatrix(newMatrixRows, newMatrixColumns);
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			newMatrix[j][i] = matrixToTranspose[i][j];
		}
	}
	return newMatrix;
}

double** matrixSum(double** firstMatrix, int rowCountFirst, int columnCountFirst, double** secondMatrix, int rowCountSecond, int columnCountSecond)
{
	if (rowCountFirst != rowCountSecond || columnCountFirst != columnCountSecond)
	{
		printf_s("Wrong size of matrix!\n");
		return NULL;
	}
	double** newMatrix = allocMatrix(rowCountFirst, columnCountFirst);
	for (int i = 0; i < rowCountFirst; i++)
	{
		for (int j = 0; j < columnCountFirst; j++)
		{
			newMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
		}
	}
	return newMatrix;
}

double** matrixSubstitution(double** firstMatrix, int rowCountFirst, int columnCountFirst, double** secondMatrix, int rowCountSecond, int columnCountSecond)
{
	if (rowCountFirst != rowCountSecond || columnCountFirst != columnCountSecond)
	{
		printf_s("Wrong size of matrix!\n");
		return NULL;
	}
	double** newMatrix = allocMatrix(rowCountFirst, columnCountFirst);
	for (int i = 0; i < rowCountFirst; i++)
	{
		for (int j = 0; j < columnCountFirst; j++)
		{
			newMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
		}
	}
	return newMatrix;
}

double** allocMatrix(int rowCount, int columnCount)
{
	double** matrix = (double**)malloc(rowCount * sizeof(double*));
	if (matrix == NULL)
	{
		perror("");
		exit(1);
	}
	for (int i = 0; i < rowCount; i++)
	{
		matrix[i] = (double*)malloc(columnCount * sizeof(double));
		if (!(matrix[i]))
		{
			for (int j = i; j >= 0; j--)
			{
				free(matrix[j]);
			}
			perror("");
			free(matrix);
			exit(1);
		}
	}
	return matrix;
}
void printMatrix(double** matrix, int rowCount, int columnCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			printf_s("%.2f\t", matrix[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}
void fillInMatrixRandom(double** matrix, int rowCount, int columnCount)
{
	srand((unsigned)time(0));
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			double tmp = (double)(rand() % 11 + 1);
			matrix[i][j] = tmp;
		}
	}
}

void freeMatrix(double** matrix, int rowCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}
double getDeterminant(double** matrix, int rowCount, int columnCount, bool* detFlag)
{
	if (rowCount != columnCount)
	{
		*detFlag = 0;
		return 0.0;
	}
	double sign = 1.0;
	for (int i = 0; i < rowCount - 1; i++)
	{

		if (matrix[i][i] == 0.0)
		{
			for (int k = i; k < rowCount; k++)
			{
				if (matrix[k][i] != 0.0)
				{
					swapTwoLine(matrix[k], matrix[i]);
					sign = sign == 1.0 ? -1.0 : 1.0;
					break;
				}
			}
			if (matrix[i][i] == 0.0)
			{
				*detFlag = 1;
				return 0.0;
			}
		}
		for (int k = i + 1; k < rowCount; k++)
		{
			double coeff = (matrix[k][i] / matrix[i][i]);
			multAndSub(matrix[i], matrix[k], coeff, rowCount);
		}
	}
	double det = 1.0;
	for (int i = 0, j = 0; i < rowCount; i++, j++)
	{
		det *= matrix[i][j];
	}
	*detFlag = 1;
	return det * sign;
}

void multAndSub(double* firstArr, double* secondArr, double coef, int len)
{
	for (int i = 0; i < len; i++)
	{
		secondArr[i] = secondArr[i] - (firstArr[i] * coef);
	}
}


void swapTwoLine(double** line1, double** line2)
{
	double* tmp = *line1;
	*line1 = *line2;
	*line2 = tmp;
}

double** readMatrixFromFile(int rowCount, int columnsCount, FILE* file)
{
	fseek(file, 0, 0);
	double** matrix = allocMatrix(rowCount, columnsCount);
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)
		{
			fscanf_s(file, "%lf", &matrix[i][j]);
		}
	}
	fseek(file, 0, 0);
	return matrix;
}

int findCountOfRows(FILE* file)
{
	return countLinesInFile(file);
}

int findCountOfColumns(FILE* file)
{
	fseek(file, 0, 0);
	char* firstFileString = (char*)malloc(MAX_STR_LEN * sizeof(char));
	fgets(firstFileString, MAX_STR_LEN, file);
	firstFileString = removeExtraSpaces(firstFileString);
	return countSymbols(firstFileString, ' ') + 1;
	fseek(file, 0, 0);
}