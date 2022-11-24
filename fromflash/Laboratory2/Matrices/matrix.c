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
int multiplyMatrices(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* resultMatrix)
{
	if (firstMatrix->columns != secondMatrix->rows)
	{
		printf_s("Wrong size of matrix!\n");
		return 0;
	}
	allocMatrix(resultMatrix, firstMatrix->rows, secondMatrix->columns);
	for (int i = 0; i < firstMatrix->rows; i++)
	{
		for (int j = 0; j < secondMatrix->columns; j++)
		{
			double sum = 0.0;
			for (int k = 0; k < firstMatrix->columns; k++)
			{
				sum += (firstMatrix->data[i][k] * secondMatrix->data[k][j]);
			}
			resultMatrix->data[i][j] = sum;
		}
	}
	return 1;
}

int transpose(Matrix* matrixToTranspose, Matrix* resultMatrix)
{
	int resultMatrixRows = matrixToTranspose->columns;
	int resultMatrixColumns = matrixToTranspose->rows;
	allocMatrix(resultMatrix, resultMatrixRows, resultMatrixColumns);
	for (int i = 0; i < matrixToTranspose->rows; i++)
	{
		for (int j = 0; j < matrixToTranspose->columns; j++)
		{
			resultMatrix->data[j][i] = matrixToTranspose->data[i][j];
		}
	}
	return 1;
}

int matrixSum(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* newMatrix)
{
	if (firstMatrix->rows != secondMatrix->rows || firstMatrix->columns != secondMatrix->columns)
	{
		printf_s("Wrong size of matrix!\n");
		return 0;
	}
	allocMatrix(newMatrix, firstMatrix->rows, firstMatrix->columns);
	for (int i = 0; i < firstMatrix->rows; i++)
	{
		for (int j = 0; j < firstMatrix->columns; j++)
		{
			newMatrix->data[i][j] = firstMatrix->data[i][j] + secondMatrix->data[i][j];
		}
	}
	return 1;
}

int matrixSubstitution(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* newMatrix)
{
	if (firstMatrix->rows != secondMatrix->rows || firstMatrix->columns != secondMatrix->columns)
	{
		printf_s("Wrong size of matrix!\n");
		return 0;
	}
	allocMatrix(newMatrix, firstMatrix->rows, firstMatrix->columns);
	for (int i = 0; i < firstMatrix->rows; i++)
	{
		for (int j = 0; j < firstMatrix->columns; j++)
		{
			newMatrix->data[i][j] = firstMatrix->data[i][j] - secondMatrix->data[i][j];
		}
	}
	return 1;
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
int getDeterminant(Matrix* matrix)
{
	if (matrix->hasDet == 1.0) return;
	if (matrix->rows != matrix->columns)
	{
		matrix->hasDet = 0;
		matrix->det = 0.0;
		return 1;
	}
	Matrix* matrixCopy = (Matrix*)malloc((sizeof(Matrix)));
	allocMatrix(matrixCopy, matrix->rows, matrix->columns);
	copyData(matrix, matrixCopy);
	double sign = 1.0;
	for (int i = 0; i < matrixCopy->rows - 1; i++)
	{

		if (matrixCopy->data[i][i] == 0.0)
		{
			for (int k = i; k < matrixCopy->rows; k++)
			{
				if (matrixCopy->data[k][i] != 0.0)
				{
					swapTwoLine(matrixCopy->data[k], matrixCopy->data[i]);
					sign = sign == 1.0 ? -1.0 : 1.0;
					break;
				}
			}
			if (matrixCopy->data[i][i] == 0.0)
			{
				matrixCopy->hasDet = 1;
				matrixCopy->det = 0.0;
				return 1;
			}
		}
		for (int k = i + 1; k < matrixCopy->rows; k++)
		{
			double coeff = (matrixCopy->data[k][i] / matrixCopy->data[i][i]);
			multAndSub(matrixCopy->data[i], matrixCopy->data[k], coeff, matrixCopy->rows);
		}
	}
	matrixCopy->det = 1.0;
	for (int i = 0, j = 0; i < matrixCopy->rows; i++, j++)
	{
		matrixCopy->det *= matrixCopy->data[i][j];
	}
	matrix->hasDet = 1;
	matrix->det = matrixCopy->det * sign;
	freeMatrix(matrixCopy);
	free(matrixCopy);
	return 1;
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

int changeMatrix(Matrix* matrix, unsigned indexRow, unsigned indexColumn)
{
	if (indexRow <= matrix->rows && indexColumn <= matrix->columns)
	{
		printf_s("Enter the value:\n>");
		scanf_s("%lf", &matrix->data[indexRow - 1][indexColumn - 1]);
	}
	else if (indexRow == 0 || indexColumn == 0)
	{
		printf_s("Positions start with 1!\n");
	}
	else
	{
		printf_s("Enter the position correctly!\n");
	}
	
}