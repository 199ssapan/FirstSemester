#include "matrix.h"
#include "checking.h"
#include "mainMenu.h"
int main()
{
	FILE* file1, * file2;
	if (fopen_s(&file1, "file1.txt", "r")) errex("");
	if (fopen_s(&file2, "file2.txt", "r")) errex("");
	checkFile(file1, "file1.txt");
	checkFile(file2, "file2.txt");


	while (mainMenu(file1, file2)) {};
	printf_s("Good Bye!\n");
	return 0;
}


