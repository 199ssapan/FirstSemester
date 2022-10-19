#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf_s("Enter quantity of the strings and max length of string\n>");
	int stringsCount, maxLen;
	scanf_s("%d %d", &stringsCount, &maxLen);
	char** stringsArr = (char**)malloc(stringsCount * sizeof(char*));
	if (!(stringsArr))
	{
		perror("");
		exit(1);
	}
	for (int i = 0; i < stringsCount; i++)
	{
		stringsArr[i] = (char*)malloc((maxLen + 1) * sizeof(char));
		if (!(stringsArr[i]))
		{
			perror("");
			exit(1);
		}
	}
	for (int i = 0; i < stringsCount; i++)
	{
		printf_s(">");
		scanf_s("%s", stringsArr[i], maxLen+1);
	}
	printf_s("%d strings were entered\n", stringsCount);
	for (int i = 0; i < stringsCount; i++)
	{
		printf_s("%s (len = %d)\n", stringsArr[i], strlen(stringsArr[i]));
	}
	for (int i = 0; i < stringsCount; i++)
	{
		free(stringsArr[i]);
	}
	free(stringsArr);
	return 0;
}