#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned storage = 0;
	for (int i = 1; i < argc; i++)
	{
		unsigned shift = atoi(argv[i]);
		storage |= (1 << (shift));
	}
	unsigned inputDayNumber;
	while (1)
	{
		printf_s("Enter a day number\n>");
		scanf_s("%u", &inputDayNumber);
		if (inputDayNumber > 31)
		{
			printf_s("Enter correct number!\n");
			continue;
		}
		else if (inputDayNumber == 0) break;
		(storage & (1 << inputDayNumber)) == 0 ? printf_s("Drink coffee!!!\n") : printf_s("Sleep Mode!!!\n");
	}
}