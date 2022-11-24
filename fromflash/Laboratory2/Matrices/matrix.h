#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define MAX_STR_LEN 100
#define bool char

typedef struct Matrix
{
    double** data;
    unsigned int rows;
    unsigned int columns;
    double det;
    bool hasDet;

}Matrix;

void handWriteMatrix(Matrix* matrix);
int multiplyMatrices(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* resultMatrix);
int transpose(Matrix* matrixToTranspose, Matrix* resultMatrix);
int matrixSum(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* newMatrix);
int matrixSubstitution(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* newMatrix);
void allocMatrix(Matrix* matrix, unsigned rowCount, unsigned columnCount);
void printMatrix(Matrix* matrix);
void fillInMatrixRandom(Matrix* matrix);
void freeMatrix(Matrix* matrix);
int getDeterminant(Matrix* matrix);
void multAndSub(double* firstArr, double* secondArr, double coef, int len);
void swapTwoLine(double** line1, double** line2);
void readMatrixFromFile(Matrix* matrix, FILE* file);
int findCountOfRows(FILE* file);
int findCountOfColumns(FILE* file);
int changeMatrix(Matrix* matrix, unsigned indexRow, unsigned indexColumn);