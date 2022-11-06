#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** allocMatrix(int, int);
double** transpose(double**, int, int);
double** matrixSum(double**, int, int, double**, int, int);
void printMatrix(double**, int, int);
void fillInMatrixRandom(double**, int, int);
double** multiplyMatrices(double**, int, int, double**, int, int);
void handWriteMatrix(double**, int, int);
double getDeterminant(double**, int, int);
void multAndSub(double* , double* , double, int);
void swapTwoLine(double**, double**);
void freeMatrix(double**, int);