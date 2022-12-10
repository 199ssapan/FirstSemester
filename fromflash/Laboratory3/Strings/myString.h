#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned mystrlen(char* string);
int findSubString(char* stringMain, char* substring);
int findCountOfAllSubStrings(char* stringMain, char* substring);
char** StringToArray(char* string, char separator);
unsigned countSymbols(char* string, char symbol);
char* replace(char* string, char* subOut, char* subIn);
int findCountOfSubStrings(char* stringMain, char* substring);
char* deleteExcessSymbols(char* string, char symbol);
char* delFirst(char* string);
char* delLast(char* string);