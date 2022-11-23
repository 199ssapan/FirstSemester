#include "matrix.h"
#include "mainMenu.h"
#include "checking.h"

void handWriteMatrix(Matrix* matrix)
{
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			scanf_s("%lf", &matrix->data[i][j]);
		}
	}
}
Matrix* multiplyMatrices(Matrix* firstMatrix, Matrix* secondMatrix)
{
	if (firstMatrix->columns != secondMatrix->rows)
	{
		printf_s("Wrong size of matrix!\n");
		return NULL;
	}
	Matrix resultMatrix;
	allocMatrix(&resultMatrix, firstMatrix->rows, secondMatrix->columns);
	for (int i = 0; i < firstMatrix->rows; i++)
	{
		for (int j = 0; j < secondMatrix->columns; j++)
		{
			double sum = 0.0;
			for (int k = 0; k < firstMatrix->columns; k++)
			{
				sum += (firstMatrix->data[i][k] * secondMatrix->data[k][j]);
			}
			resultMatrix.data[i][j] = sum;
		}
	}
	return &resultMatrix;
}

Matrix* transpose(Matrix* matrixToTranspose)
{
	int newMatrixRows = matrixToTranspose->columns;
	int newMatrixColumns = matrixToTranspose->rows;
	Matrix newMatrix;
	allocMatrix(&newMatrix, newMatrixRows, newMatrixColumns);
	for (int i = 0; i < matrixToTranspose->rows; i++)
	{
		for (int j = 0; j < matrixToTranspose->columns; j++)
		{
			newMatrix.data[j][i] = matrixToTranspose->data[i][j];
		}
	}
	return &newMatrix;
}

Matrix* matrixSum(Matrix* firstMatrix, Matrix* secondMatrix)
{
	if (firstMatrix->rows != secondMatrix->rows || firstMatrix->columns != secondMatrix->columns)
	{
		printf_s("Wrong size of matrix!\n");
		return NULL;
	}
	Matrix newMatrix;
	allocMatrix(&newMatrix, firstMatrix->rows, firstMatrix->columns);
	for (int i = 0; i < firstMatrix->rows; i++)
	{
		for (int j = 0; j < firstMatrix->columns; j++)
		{
			newMatrix.data[i][j] = firstMatrix->data[i][j] + secondMatrix->data[i][j];
		}
	}
	return &newMatrix;
}

Matrix* matrixSubstitution(Matrix* firstMatrix, Matrix* secondMatrix)
{
	if (firstMatrix->rows != secondMatrix->rows || firstMatrix->columns != secondMatrix->columns)
	{
		printf_s("Wrong size of matrix!\n");
		return NULL;
	}
	Matrix newMatrix;
	allocMatrix(&newMatrix, firstMatrix->rows, firstMatrix->columns);
	for (int i = 0; i < firstMatrix->rows; i++)
	{
		for (int j = 0; j < firstMatrix->columns; j++)
		{
			newMatrix.data[i][j] = firstMatrix->data[i][j] - secondMatrix->data[i][j];
		}
	}
	return &newMatrix;
}

void allocMatrix(Matrix* matrix, unsigned rowCount, unsigned columnCount)
{
	matrix->data = (double**)malloc(rowCount * sizeof(double*));
	if (matrix == NULL)
	{
		perror("");
		exit(1);
	}
	for (int i = 0; i < rowCount; i++)
	{
		matrix->data[i] = (double*)malloc(columnCount * sizeof(double));
	}
	matrix->rows = rowCount;
	matrix->columns = columnCount;
	matrix->det = 0.0;
	matrix->hasDet = 0;
}
void printMatrix(Matrix* matrix)
{
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			printf_s("%10.2f\t", matrix->data[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}
void fillInMatrixRandom(Matrix* matrix)
{
	srand((unsigned)time(0));
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			double tmp = (double)(rand() % 11 + 1);
			matrix->data[i][j] = tmp;
		}
	}
}

void freeMatrix(Matrix* matrix)
{
	for (int i = 0; i < matrix->rows; i++)
	{
		free(matrix->data[i]);
	}
}
void getDeterminant(Matrix* matrix)
{
	if (matrix->hasDet == 1.0) return;
	if (matrix->rows != matrix->columns)
	{
		matrix->hasDet = 0;
		matrix->det = 0.0;
		return;
	}
	double sign = 1.0;
	for (int i = 0; i < matrix->rows - 1; i++)
	{

		if (matrix->data[i][i] == 0.0)
		{
			for (int k = i; k < matrix->rows; k++)
			{
				if (matrix->data[k][i] != 0.0)
				{
					swapTwoLine(matrix->data[k], matrix->data[i]);
					sign = sign == 1.0 ? -1.0 : 1.0;
					break;
				}
			}
			if (matrix->data[i][i] == 0.0)
			{
				matrix->hasDet = 1;
				matrix->det = 0.0;
				return;
			}
		}
		for (int k = i + 1; k < matrix->rows; k++)
		{
			double coeff = (matrix->data[k][i] / matrix->data[i][i]);
			multAndSub(matrix->data[i], matrix->data[k], coeff, matrix->rows);
		}
	}
	matrix->det = 1.0;
	for (int i = 0, j = 0; i < matrix->rows; i++, j++)
	{
		matrix->det *= matrix->data[i][j];
	}
	matrix->hasDet = 1;
	matrix->det = matrix->det * sign;
	return;
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

void readMatrixFromFile(Matrix* matrix, FILE* file)
{
	fseek(file, 0, 0);
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			fscanf_s(file, "%lf", &matrix->data[i][j]);
		}
	}
	fseek(file, 0, 0);
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

void dswap(double* first, double* second)
{
	double tmp = *first;
	*first = *second;
	*second = tmp;
}