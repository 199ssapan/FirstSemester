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
	Matrix resultMatrix;
	Matrix** matrices = (Matrix**)malloc(2 * sizeof(Matrix*));
	matrices[0] = &firstMatrix;
	matrices[1] = &secondMatrix;
	while (1)
	{
		system("cls");
		printf_s("First matrix\n");
		printMatrix(matrices[0]);
		printf_s("Second matrix\n");
		printMatrix(matrices[1]);
		printf_s("1. Sum\n2. Substitution\n3. Multiplication\n4. Transposition\n5. Find determinant\n6. Change element in matrix\n7. Exit\n");
		char action = _getch();
		switch (action)
		{
		case '1':
			if (matrixSum(matrices[0], matrices[1], &resultMatrix))
			{
				printMatrix(&resultMatrix);
				useCurrentMatrix(&resultMatrix, matrices);
				freeMatrix(&resultMatrix);
			}
			system("pause");
			break;
		case '2':
			if (matrixSubstitution(matrices[0], matrices[1], &resultMatrix))
			{
				printMatrix(&resultMatrix);
				useCurrentMatrix(&resultMatrix, matrices);
				freeMatrix(&resultMatrix);
			}
			system("pause");
			break;
		case '3':
			if (multiplyMatrices(&firstMatrix, &secondMatrix, &resultMatrix))
			{
				printMatrix(&resultMatrix);
				useCurrentMatrix(&resultMatrix, matrices);
				freeMatrix(&resultMatrix);
			}
			system("pause");
			break;
		case '4':
			printf_s("Which matrix do you want to transpose?\n1. 1\n2. 2\n");
			action = _getch();
			switch (action)
			{
			case '1':
				if (transpose(&firstMatrix, &resultMatrix))
				{
					printMatrix(&resultMatrix);
					useCurrentMatrix(&resultMatrix, matrices);
					freeMatrix(&resultMatrix);
				}
				system("pause");
				break;
			case '2':
				if (transpose(&secondMatrix, &resultMatrix))
				{
					printMatrix(&resultMatrix);
					useCurrentMatrix(&resultMatrix, file1, filename1, file2, filename2);
					freeMatrix(&resultMatrix);
				}
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
				detCheck(matrices[0]);
				break;
			case '2':
				detCheck(matrices[1]);
				break;
			default:
				printf_s("Wrong action!\n");
				system("pause");
			}
			break;
		case '6':
			printf_s("Which matrix do you want to change?\n1. 1\n2. 2\n");
			action = _getch();
			printf_s("Enter the position which you want to change\n>");
			unsigned x = 0, y = 0;
			scanf_s("%u %u", &x, &y);
			switch (action)
			{
			case '1':
				changeMatrix(matrices[0], x, y);
				break;
			case '2':
				changeMatrix(matrices[1], x, y);
				break;
			default:
				printf_s("Wrong command!\n");
				system("pause");
				break;
			}
			break;
		case '7':
			writeToFile(matrices[0], file1, filename1);
			writeToFile(matrices[1], file2, filename2);
			freeMatrix(matrices[0]);
			freeMatrix(matrices[1]);
			free(matrices);
			return 0;
			break;
		default:
			printf_s("Wrong command!\n");
			system("pause");
		}
	}
	return 0;
}
