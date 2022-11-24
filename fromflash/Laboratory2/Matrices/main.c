#include "matrix.h"
#include "checking.h"
#include "mainMenu.h"
int main()
{
	char* filename1 = "file1.txt";
	char* filename2 = "file2.txt";
	FILE* file1, * file2;
	if (fopen_s(&file1, filename1, "r")) errex("");
	if (fopen_s(&file2, filename2, "r")) errex("");
	checkFile(file1, filename1);
	checkFile(file2, filename2);
	mainMenu(file1, filename1, file2, filename2);
	printf_s("Good Bye!\n");
	return 0;
}