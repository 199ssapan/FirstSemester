#include "list.h"

#define MAX_INPUT_STR_LEN 100
#define MAX_STR_LEN 20

int spacesCount(char* string);
char** allocMem2dArr(int count);
char** StringToWords(char* string);
int countSymbols(char* string, char symbol);


int main()
{
	FILE* file;
	if (fopen_s(&file, "file.txt", "r")) return 1;
	char* bufferString = (char*)malloc(sizeof(char) * MAX_INPUT_STR_LEN);
	fgets(bufferString, MAX_INPUT_STR_LEN, file);
	int wordsCount = spacesCount(bufferString) + 1;
	fseek(file, 0, 0);
	char** stringsArr = StringToWords(bufferString);
	List* list = createList();
	for (int i = 0; i < wordsCount; i++)
	{
		printf_s("%s ", stringsArr[i]);
	}
	for (int i = 1; i < wordsCount; i++)
	{
		pushBack(list, stringsArr[i]);
	}

	return 0;
}

int spacesCount(char* string)
{
	int count = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == ' ') count++;
	}
	return count;
}

char** allocMem2dArr(int count)
{
	char** arr = (char**)malloc(sizeof(char*) * count);
	for (int i = 0; i < count; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * MAX_STR_LEN);
	}
	return arr;
}

char** StringToWords(char* string)
{
	int spaceCount = countSymbols(string, ' ');
	int* spaceIndexArr = (int*)calloc((spaceCount + 2), sizeof(int));
	if (!(spaceIndexArr))
	{
		return NULL;
	}
	spaceIndexArr[0] = -1;
	spaceIndexArr[spaceCount + 1] = strlen(string);
	int new_i = 1;
	for (int i = 1; i < strlen(string); i++)
	{
		if (string[i] == ' ')
		{
			spaceIndexArr[new_i] = i;
			new_i++;
		}
	}
	int wordsCount = spaceCount + 1;
	char** wordsArr = (char**)malloc(wordsCount * sizeof(char*));
	if (!(wordsArr))
	{
		return NULL;
	}
	for (int i = 0; i < wordsCount; i++)
	{
		int lettersCount = spaceIndexArr[i + 1] - spaceIndexArr[i] - 1;
		wordsArr[i] = (char*)malloc((lettersCount + 1) * sizeof(char));
		if (!(wordsArr[i]))
		{
			for (int j = 0; j < i; j++)
			{
				free(wordsArr[j]);
			}
			break;
			return NULL;
		}
		strncpy(wordsArr[i], string + spaceIndexArr[i] + 1, lettersCount);
		wordsArr[i][lettersCount] = '\0';
	}
	return wordsArr;
}

int countSymbols(char* string, char symbol)
{
	int countSymb = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == symbol)
		{
			countSymb++;
		}
	}
	return countSymb;

}
