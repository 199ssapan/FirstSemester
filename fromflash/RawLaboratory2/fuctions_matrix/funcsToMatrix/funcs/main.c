#include "matrix.h"
#include "checking.h"

int main()
{
	FILE* file1, *file2;
	if (fopen_s(&file1, "file1.txt", "r")) errex();
	if (fopen_s(&file2, "file2.txt", "r")) errex();
	if (isMatrix(file1, "file1.txt")) errex();// printf_s("wrong data");//
	
	printf_s("%d", isMatrix(file1, "file1.txt"));
	return 0;
}

