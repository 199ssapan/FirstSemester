#include "myString.h"

int findIndexFirstSubString(char* stringMain, char* substring)
{ 
	unsigned lenMain = mystrlen(stringMain);
	unsigned lenSub = mystrlen(substring);
	if (lenSub > lenMain || lenSub == 0 || lenMain == 0) return -1;
	for (int i = 0; i < lenMain - lenSub + 1; i++)
	{
		unsigned count = 0;
		for (int j = 0; j < lenSub; j++)
		{
			if (substring[j] == stringMain[i + j]) count++;
		}
		if (count == lenSub) return i;
	}
	return -1;
}

char** StringToArray(char* rawString, char separator)
{
	char* string = deleteExcessSymbols(rawString, separator);
	if (string[0] == separator) string = delFirst(string);
	if (string[mystrlen(string) - 1] == separator) string = delLast(string);
	if (mystrlen(string) == 1 && string[0] == separator || mystrlen(string) == 0) printError("Wring string!");
	int firstIndex = 0;
	int sepCount = countSymbols(string, separator);
	int* sepIndexArr = (int*)calloc((sepCount + 2), sizeof(int));
	if (!(sepIndexArr))
	{
		printError(MEM_ALL_ERR);
	}
	sepIndexArr[0] = -1;
	sepIndexArr[sepCount + 1] = mystrlen(string);
	int new_i = 1;
	for (int i = 1; i < mystrlen(string); i++)
	{
		if (string[i] == separator)
		{
			sepIndexArr[new_i] = i;
			new_i++;
		}
	}
	int stringsCount = sepCount + 1;
	char** stringsArray = (char**)malloc(stringsCount * sizeof(char*));
	if (!(stringsArray))
	{
		printError(MEM_ALL_ERR);
	}
	for (int i = 0; i < stringsCount; i++)
	{
		int lettersCount = sepIndexArr[i + 1] - sepIndexArr[i] - 1;
		stringsArray[i] = (char*)malloc((lettersCount + 1) * sizeof(char));
		if (!(stringsArray[i]))
		{
			for (int j = 0; j < i; j++)
			{
				free(stringsArray[j]);
			}
			break;
			printError(MEM_ALL_ERR);
		}
		memcpy(stringsArray[i], string + sepIndexArr[i] + 1, lettersCount);
		stringsArray[i][lettersCount] = '\0';
	}
	return stringsArray;
}

int findCountOfSubStrings(char* stringMain, char* substring)
{
	unsigned lenMain = mystrlen(stringMain);
	unsigned lenSub = mystrlen(substring);
	if (lenSub > lenMain) return -1;
	if (lenSub == 0) return -1;
	unsigned subCount = 0;
	for (int i = 0; i < lenMain - lenSub + 1; i++)
	{
		unsigned matchCount = 0;
		for (int j = 0; j < lenSub; j++)
		{
			if (substring[j] == stringMain[i + j]) matchCount++;
		}
		if (matchCount == lenSub)
		{
			subCount++;
			i += lenSub - 1;
		}
	}
	return subCount;
}

char* replace(char* string, char* subOut, char* subIn)
{
	if (findIndexFirstSubString(string, subOut) == -1 || mystrlen(subOut) == 0 || mystrlen(subIn) == 0) return NULL;
	unsigned len = mystrlen(string);
	unsigned lenOut = mystrlen(subOut);
	unsigned lenIn = mystrlen(subIn);
	unsigned newLen = len + lenIn - lenOut;
	char* newString = (char*)malloc(sizeof(char) * (newLen + 1));
	int occurrenceIndex = findIndexFirstSubString(string, subOut);
	for (int i = 0; i < occurrenceIndex; i++)
	{
		newString[i] = string[i];
	}
	int new_i = 0;
	for (int i = occurrenceIndex; i < occurrenceIndex + lenIn; i++)
	{
		newString[i] = subIn[new_i];
		new_i++;
	}
	for (int i = occurrenceIndex + lenOut; i < len; i++)
	{
		newString[i + lenIn - lenOut] = string[i];
	}
	newString[newLen] = '\0';
	return newString;
}

//ADDITIONAL AND AUXILIARY FUNCTIONS
//ADDITIONAL AND AUXILIARY FUNCTIONS
//ADDITIONAL AND AUXILIARY FUNCTIONS

int findCountOfIntersectingSubStrings(char* stringMain, char* substring)
{
	unsigned lenMain = mystrlen(stringMain);
	unsigned lenSub = mystrlen(substring);
	if (lenSub > lenMain || lenMain == 0 || lenSub == 0) return 0;
	unsigned subCount = 0;
	for (int i = 0; i < lenMain - lenSub + 1; i++)
	{
		unsigned matchCount = 0;
		for (int j = 0; j < lenSub; j++)
		{
			if (substring[j] == stringMain[i + j]) matchCount++;
		}
		if (matchCount == lenSub) subCount++;
	}
	return subCount;
}

unsigned mystrlen(char* string)
{
	unsigned count = 0;
	for (int i = 0; string[i] != '\0'; i++)
		count++;
	return count;
}

unsigned countSymbols(char* string, char symbol)
{
	unsigned countSymb = 0;
	for (int i = 0; i < mystrlen(string); i++)
	{
		if (string[i] == symbol)
		{
			countSymb++;
		}
	}
	return countSymb;
}

char* deleteExcessSymbols(char* string, char symbol)
{
	int len = mystrlen(string);
	if (len == 0)
	{
		return "";
	}
	char* stringToReturn = (char*)malloc(len * sizeof(char));
	int new_i = 0;
	int flag = 0;
	for (int i = 0; i < len;i++)
	{
		if (string[i] != symbol)
		{
			stringToReturn[new_i] = string[i];
			new_i++;
			flag = 0;
		}
		else if (flag == 1) {}
		else
		{
			stringToReturn[new_i] = string[i];
			new_i++;
			flag = 1;
		}
	}
	stringToReturn[new_i] = '\0';
	return stringToReturn;
}

char* delFirst(char* string)
{
	unsigned len = mystrlen(string);
	char* newString = (char*)malloc(sizeof(char) * len);
	for (int i = 1; i < len; i++)
	{
		newString[i - 1] = string[i];
	}
	newString[len - 1] = '\0';
	return newString;
}

char* delLast(char* string)
{
	unsigned len = mystrlen(string);
	char* newString = (char*)malloc(sizeof(char) * len);
	for (int i = 0; i < len - 1; i++)
	{
		newString[i] = string[i];
	}
	newString[len - 1] = '\0';
	return newString;
}

void printError(char* errorText)
{
	printf_s("%s\n", errorText);
	exit(1);
}