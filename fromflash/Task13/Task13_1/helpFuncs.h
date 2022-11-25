#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** StringToWords(char* string);
void errex(void);
int countSymbols(char* string, char symbol);
char* putSpaces(char* string);
int countLetters(char* string);
char** allocMem2d(int d1, int d2);
void printResult(int sumsOfSteps[4]);
void exceptTwoSides(int sumsOfSteps[4]);
