#include "myString.h"

int findSubString(char* stringMain, char* substring)
{
	unsigned lenMain = mystrlen(stringMain);
	unsigned lenSub = mystrlen(substring);
	if (lenSub > lenMain) return 0;
	if (lenSub == 0) return 0;
	for (int i = 0; i < lenMain - lenSub + 1; i++)
	{
		unsigned count = 0;
		for (int j = 0; j < lenSub; j++)
		{
			if (substring[j] == stringMain[i + j]) count++;
		}
		if (count == lenSub) return i;
	}
	return 0;
}

int findCountOfAllSubStrings(char* stringMain, char* substring)
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

char** StringToArray(char* string, char separator)
{
	int sepCount = countSymbols(string, separator);
	int* sepIndexArr = (int*)calloc((sepCount + 2), sizeof(int));
	if (!(sepIndexArr))
	{
		exit(1);
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
		exit(1);
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
			exit(1);
		}
		memcpy(stringsArray[i], string + sepIndexArr[i] + 1, lettersCount);
		stringsArray[i][lettersCount] = '\0';
	}
	return stringsArray;
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


char* replace(char* string, char* subOut, char* subIn)
{
	if (findSubString(string, subOut) == -1 || mystrlen(subOut) == 0 || mystrlen(subIn) == 0) return NULL;
	unsigned len = mystrlen(string);
	unsigned lenOut = mystrlen(subOut);
	unsigned lenIn = mystrlen(subIn);
	unsigned newLen = len + lenIn - lenOut;
	char* newString = (char*)malloc(sizeof(char) * (newLen + 1));
	int occurrenceIndex = findSubString(string, subOut);
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