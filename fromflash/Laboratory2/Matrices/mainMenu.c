#include "mainMenu.h"
#include "checking.h"
#include "matrix.h"
int mainMenu(FILE* file1, char* filename1, FILE* file2, char* filename2)
{
	int rowCountFirst = findCountOfRows(file1);
	int columnCountFirst = findCountOfColumns(file1);
	int rowCountSecond = findCountOfRows(file2);
	int columnCountSecond = findCountOfColumns(file2);
	double** firstMatrix = readMatrixFromFile(rowCountFirst, columnCountFirst, file1);
	double** secondMatrix = readMatrixFromFile(rowCountSecond, columnCountSecond, file2);
	system("cls");
	printf_s("First matrix\n");
	printMatrix(firstMatrix, rowCountFirst, columnCountFirst);
	printf_s("Second matrix\n");
	printMatrix(secondMatrix, rowCountSecond, columnCountSecond);
	printf_s("1. Sum\n2. Substitution\n3. Multiplication\n4. Transposition\n5. Find determinant\n6. Exit\n");
	double** resultMatrix;
	char action = _getch();
	switch (action)
	{
	case '1':
		resultMatrix = matrixSum(firstMatrix, rowCountFirst, columnCountFirst, secondMatrix, rowCountSecond, columnCountSecond);
		if (resultMatrix)
		{
			printMatrix(resultMatrix, rowCountFirst, columnCountFirst);
			useCurrentMatrix(resultMatrix, rowCountFirst, columnCountFirst, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix, rowCountFirst);
		}
		system("pause");
		break;
	case '2':
		resultMatrix = matrixSubstitution(firstMatrix, rowCountFirst, columnCountFirst, secondMatrix, rowCountSecond, columnCountSecond);
		if (resultMatrix)
		{
		    printMatrix(resultMatrix, rowCountFirst, columnCountFirst);
			useCurrentMatrix(resultMatrix, rowCountFirst, columnCountFirst, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix, rowCountFirst);
		}
		system("pause");
		break;
	case '3':
		resultMatrix = multiplyMatrices(firstMatrix, rowCountFirst, columnCountFirst, secondMatrix, rowCountSecond, columnCountSecond);
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
			resultMatrix = transpose(firstMatrix, rowCountFirst, columnCountFirst);
			printMatrix(resultMatrix, columnCountFirst, rowCountFirst);
			useCurrentMatrix(resultMatrix, columnCountFirst, rowCountFirst, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix, columnCountFirst);
			system("pause");
			break;
		case '2':
			resultMatrix = transpose(secondMatrix, rowCountSecond, columnCountSecond);
			printMatrix(resultMatrix, columnCountSecond, rowCountSecond);
			useCurrentMatrix(resultMatrix, columnCountSecond, rowCountSecond, file1, filename1, file2, filename2);
			freeMatrix(resultMatrix, columnCountSecond);
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
			bool isDetFlag = 0;
		case '1':
			det = getDeterminant(firstMatrix, rowCountFirst, columnCountFirst, &isDetFlag);
			 isDetFlag == 1 ? printf_s("Determinant is %lf\n", det) : printf_s("Not square matrix!\nNot possible to find determinant\n");
			system("pause");
			break;
		case '2':
			det = getDeterminant(secondMatrix, rowCountSecond, columnCountSecond, &isDetFlag);
			isDetFlag == 1 ? printf_s("Determinant is %lf\n", det) : printf_s("Not square matrix!\nNot possible to find determinant\n");
			system("pause");
			break;
		default:
			printf_s("Wrong action!\n");
			system("pause");
		}
		break;
	case '6':
		freeMatrix(firstMatrix, rowCountFirst);
		freeMatrix(secondMatrix, rowCountSecond);
		return 0;
		break;
	default:
		printf_s("Wrong command!\n");
		system("pause");
	}
	freeMatrix(firstMatrix, rowCountFirst);
	freeMatrix(secondMatrix, rowCountSecond);
	return 1;
}
