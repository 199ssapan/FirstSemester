#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100
char* concat(char* s1, char* s2);
char** StringToWords(char* string);
int countSymbols(char* string, char symbol);
char** decodeStringOfText(char* inputString);
int countLinesInFile(FILE* file);
char** TextToStrings(char*** textWords, FILE* file);
void errex(void);
char** lexGraphSorting(char** stringsOfText, int linesCount);
