#include "myString.h"

#define MAX_STR_LEN 150

void swap(char* a, char* b);
void printStrings(char** arr, int size);
void notBubbleSort(int* arr, int count);

int main()
{
	FILE* file;
	fopen_s(&file, "file.txt", "r");
	char* bufferstring = (char*)malloc(sizeof(char) * MAX_STR_LEN);
	int num = atoi(fgets(bufferstring, MAX_STRING_LEN, file));
	fgets(bufferstring, MAX_STR_LEN, file);
	fclose(file);
	int wordsCount = countSymbols(bufferstring, ' ') + 1;
	if (num > wordsCount) return 0;
	int* lenArr = (char*)malloc(sizeof(char) * wordsCount);
	char** stringsArr = StringToWords(bufferstring, lenArr);
	if (num == wordsCount)
	{
		printStrings(stringsArr, wordsCount);
		return 0;
	}
	notBubbleSort(lenArr, wordsCount);
	int suitableLen = lenArr[num - 1];
	int count = 0;
	for (int i = 0; i < wordsCount; i++)
	{
		if (strlen(stringsArr[i]) < suitableLen) continue;
		printf_s("%s ", stringsArr[i]);
	}
	return 0;
}

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void printStrings(char** arr, int size)
{
	for (int i = 0; i < size; i++) printf_s("%s ", arr[i]);
}
 

void notBubbleSort(int* arr, int count)
{
	int left = 0, right = count - 1;
	int flag = 1;
	while (left < right && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (arr[i - 1] < arr[i])
			{
				int tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
				flag = 1;
			}
		}
		left++;
	}
}