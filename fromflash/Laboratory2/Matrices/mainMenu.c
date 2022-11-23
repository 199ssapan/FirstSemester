#include "mainMenu.h"
#include "checking.h"
#include "matrix.h"
int mainMenu(FILE* file1, char* filename1, FILE* file2, char* filename2)
{
	Matrix firstMatrix;
	Matrix secondMatrix;
	int rowCountFirst = findCountOfRows(file1);
	int columnCountFirst = findCountOfColumns(file1);
	int rowCountSecond = findCountOfRows(file2);
	int columnCountSecond = findCountOfColumns(file2);
	allocMatrix(&firstMatrix, rowCountFirst, columnCountFirst);
	allocMatrix(&secondMatrix, rowCountSecond, columnCountSecond);
	readMatrixFromFile(&firstMatrix, file1);
	readMatrixFromFile(&secondMatrix, file2);
	system("cls");
	printf_s("First matrix\n");
	printMatrix(&firstMatrix);
	printf_s("Second matrix\n");
	printMatrix(&secondMatrix);
	printf_s("1. Sum\n2. Substitution\n3. Multiplication\n4. Transposition\n5. Find determinant\n6. Exit\n");
	Matrix* resultMatrix;
	char action = _getch();
	switch (action)
	{
	case '1':
		resultMatrix = matrixSum(&firstMatrix, &secondMatrix);
		if (resultMatrix)
		{
			printMatrix(resultMatrix, rowCountFirst, columnCountFirst);
			useCurrentMatrix(resultMatrix, rowCountFirst, columnCountFirst, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix, rowCountFirst);
		}
		system("pause");
		break;
	case '2':
		resultMatrix = matrixSubstitution(&firstMatrix, &secondMatrix);
		if (resultMatrix)
		{
		    printMatrix(resultMatrix, rowCountFirst, columnCountFirst);
			useCurrentMatrix(resultMatrix, rowCountFirst, columnCountFirst, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix, rowCountFirst);
		}
		system("pause");
		break;
	case '3':
		resultMatrix = multiplyMatrices(&firstMatrix, &secondMatrix);
		if (resultMatrix)
		{
			printMatrix(resultMatrix, rowCountFirst, columnCountSecond);
			useCurrentMatrix(resultMatrix, rowCountFirst, columnCountSecond, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix, rowCountFirst);
		}
		system("pause");
		break;
	case '4':
		printf_s("Which matrix do you want to transpose?\n1. 1\n2. 2\n");
		action = _getch();
		switch (action)
		{
		case '1':
			resultMatrix = transpose(&firstMatrix);
			printMatrix(resultMatrix);
			useCurrentMatrix(resultMatrix, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix);
			system("pause");
			break;
		case '2':
			resultMatrix = transpose(&secondMatrix, rowCountSecond, columnCountSecond);
			printMatrix(resultMatrix, columnCountSecond, rowCountSecond);
			useCurrentMatrix(resultMatrix, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix);
			system("pause");
			break;
		default:
			printf_s("Wrong action!\n");
			system("pause");
		}
		break;
	case '5':
		printf_s("For which matrix do you want to find determinant?\n1. 1\n2. 2\n");
		action = _getch();
		double det;
		switch (action)
		{
		case '1':
			getDeterminant(&firstMatrix);
			firstMatrix.hasDet == 0.0 ? printf_s("Matrix has no detereminant!\n") : printf_s("Determinant is %lf", firstMatrix.det);
			system("pause");
			break;
		case '2':
			secondMatrix.hasDet == 0.0 ? printf_s("Matrix has no detereminant!\n") : printf_s("Determinant is %lf", secondMatrix.det);
			getDeterminant(&secondMatrix);
			system("pause");
			break;
		default:
			printf_s("Wrong action!\n");
			system("pause");
		}
		break;
	case '6':
		freeMatrix(&firstMatrix);
		freeMatrix(&secondMatrix);
		return 0;
		break;
	default:
		printf_s("Wrong command!\n");
		system("pause");
	}
	freeMatrix(&firstMatrix);
	freeMatrix(&secondMatrix);
	return 1;
}
