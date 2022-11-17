#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STR_LEN 100

double** allocMatrix(int rowCount, int columnCount);
double** transpose(double** matrixToTranspose, int rowCount, int columnCount);
double** matrixSum(double** firstMatrix, int rowCountFirst, int columnCountFirst, double** secondMatrix, int rowCountSecond, int columnCountSecond);
void printMatrix(double** matrix, int rowCount, int columnCount);
void fillInMatrixRandom(double** matrix, int rowCount, int columnCount);
double** multiplyMatrices(double** firstMatrix, int rowCountFirst, int columnCountFirst, double** secondMatrix, int rowCountSecond, int columnCountSecond);
void handWriteMatrix(double** matrix, int rowCount, int columnCount);
double getDeterminant(double** matrix, int rowCount, int columnCount);
void multAndSub(double* firstArr, double* secondArr, double coef, int len);
void swapTwoLine(double** line1, double** line2);
void freeMatrix(double** matrix, int rowCount);
double** readMatrixFromFile(int rowCount, int columnsCount, FILE* file);
double** matrixSubstitution(double** firstMatrix, int rowCountFirst, int columnCountFirst, double** secondMatrix, int rowCountSecond, int columnCountSecond);
int countLinesInFile(FILE* file);
void rewritingToFile(FILE* file, char* filename, int linesCount);
char* removeExtraSpaces(char* string);
int findCountOfColumns(FILE* file);
int findCountOfRows(FILE* file);
int countSymbols(char* string, char symbol);

