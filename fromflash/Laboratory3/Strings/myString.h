#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_ALL_ERR "Memory allocation error!"

int findSubString(char* stringMain, char* substring);
char** StringToArray(char* string, char separator);
char* replace(char* string, char* subOut, char* subIn);
int findCountOfSubStrings(char* stringMain, char* substring);

//ADDITIONAL AND AUXILIARY FUNCTIONS
char* deleteExcessSymbols(char* string, char symbol);
char* delFirst(char* string);
char* delLast(char* string);
void printError(char* errorText);
unsigned mystrlen(char* string);
int findCountOfIntersectingSubStrings(char* stringMain, char* substring);
unsigned countSymbols(char* string, char symbol);
