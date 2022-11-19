#include "matrix.h"
#include "checking.h"

int main()
{
	FILE* file1, * file2;
	if (fopen_s(&file1, "file1.txt", "r")) errex("");
	if (fopen_s(&file2, "file2.txt", "r")) errex("");
	checkFiles(file1, "file1.txt");
	checkFiles(file2, "file2.txt");

	int firstRows = findCountOfRows(file1);
	int firstColumns = findCountOfColumns(file1);
	int secondRows = findCountOfRows(file2);
	int secondColumns = findCountOfColumns(file2);

	double** matrix1 = readMatrixFromFile(firstRows, firstColumns, file1);
	double** matrix2 = readMatrixFromFile(secondRows, secondColumns, file2);
	printf_s("First matrix:\n");
	printMatrix(matrix1, firstRows, firstColumns);
	printf_s("Second matrix:\n");
	printMatrix(matrix2, secondRows, secondColumns);
	double** summedMatrix = matrixSum(matrix1, firstRows, firstColumns, matrix2, secondRows, secondColumns);
	printMatrix(summedMatrix, firstRows, firstColumns);
	double** multipliedMatrix = multiplyMatrices(matrix1, firstRows, firstColumns, matrix2, secondRows, secondColumns);
	printMatrix(multipliedMatrix, firstRows, secondColumns);
	double** subbedMatrix = matrixSubstitution(matrix1, firstRows, firstColumns, matrix2, secondRows, secondColumns);
	printMatrix(subbedMatrix, firstRows, firstColumns);
	double** transedMatrix = transpose(matrix1, firstRows, firstColumns);
	double det = getDeterminant(multipliedMatrix, firstRows, secondColumns);
	printf_s("%d", det);
	return 0;
}


