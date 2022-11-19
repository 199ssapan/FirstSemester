#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include <limits.h>
int isMatrix(FILE* file, char** filename);
void errex(char* text);
int isExcessSymbols(FILE* file);
int isBigNumber(FILE* file);
int checkStringToWords(char* string);
void checkFiles(FILE* file, char* filename);
