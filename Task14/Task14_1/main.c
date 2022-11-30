#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

int main(int argc, char* argv[])
{
	char* string = argv[1];
	char ascii[ASCII_SIZE] = { 0 };
	for (int i = 0; i < strlen(string); i++)
	{
		ascii[(int)string[i]]++;
	}
	int sum = 0;
	for (int i = 0; i < ASCII_SIZE; i++)
	{
		if (ascii[i] > 1) sum += ascii[i];
	}
	printf_s("%d\n", sum);
	return 0;
}