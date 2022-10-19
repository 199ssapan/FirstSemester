#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int stringsCount = 5;//atoi(argv[1]);
	int maxLen = 7;//atoi(argv[2]);
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
			for (int j = 0; j < i; j++)
			{
				free(stringsArr[j]);
			}
			perror("");
			exit(1);
		}
	}
	for (int i = 0; i < stringsCount; i++)
	{
		printf_s(">");
		scanf_s("%s", stringsArr[i], maxLen + 1);
	}
	for (int i = 0; i < stringsCount; i++)
	{
		for (int j = 0; j < strlen(stringsArr[i]) / 2; j++)
		{
			char tmp;
			tmp = stringsArr[i][j];
			stringsArr[i][j] = stringsArr[i][strlen(stringsArr[i]) - 1 - j];
			stringsArr[i][strlen(stringsArr[i]) - 1 - j] = tmp;
		}
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