#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define TABLE_ASCII_SIZE 255
int isRealToForm(int asciiTable[TABLE_ASCII_SIZE]);

int main(int argc, char* argv[])
{
	char* fstring = argv[1];
	char* bufferString = (char*)malloc(sizeof(char) * MAX_SIZE);
	while (1)
	{
		printf_s("Enter a string\n>");
		gets_s(bufferString, MAX_SIZE);
		if (strlen(bufferString) == 0)
		{
			break;
		}
		int ascii[256] = { 0 };
		for (int i = 0; i < strlen(fstring); i++)
		{
			ascii[(int)fstring[i]]++;
		}
		for (int i = 0; i < strlen(bufferString); i++)
		{
			int index = (int)(bufferString[i]);
			ascii[index]--;
		}
		int flag = isRealToForm(ascii);
		flag == 0 ? printf_s("True!\n") : printf_s("False!\n");
	}
	printf_s("Good Bye!");
	return 0;
}

int isRealToForm(int asciiTable[TABLE_ASCII_SIZE])
{
	int flag = 0;
	for (int i = 0; i < TABLE_ASCII_SIZE; i++)
	{
		if (asciiTable[i] < 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}