#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include <limits.h>
int isMatrix(FILE* file, char* filename);
void errex(char* text);
int isExcessSymbols(FILE* file);
int isBigNumber(FILE* file);
int checkStringToWords(char* string);
void checkFile(FILE* file, char* filename);
void writeToFile(Matrix* matrix, FILE* file, char* filename);
void useCurrentMatrix(Matrix* matrix, Matrix* matrices[2]);
int countLinesInFile(FILE* file);
char* removeExtraSpaces(char* string);
int countSymbols(char* string, char symbol);
void rewritingToFile(FILE* file, char* filename, int linesCount);
void copyData(Matrix* matrixFrom, Matrix* matrixTo);
void detCheck(Matrix* matrix);
