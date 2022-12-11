#include "myString.h"

void test();

int main()
{
	test();
	return 0;
}

void test()
{
	char* string = "Hello";
	char* sub = "ell";
	char* nSub = "ss";
	if (findIndexFirstSubString(string, "ell")) printf_s("There is %s in %s\n", sub, string);
	if (findIndexFirstSubString(string, nSub) == -1) printf_s("There is no %s in %s\n", nSub, string);

	char* oneMoreString = "1231231190991Hello23321123Hey";
	char* newSub = "123";
	printf_s("There is %d occurrences of %s in string %s\n", findCountOfSubStrings(oneMoreString, newSub), newSub, oneMoreString);
	
	char* newString = "There@is@a@string@separated@by";
	int countsep = findCountOfSubStrings(newString, "@");
	char** stringsArr = StringToArray(newString, '@');
	for (int i = 0; i < countsep + 1; i++)
	{
		printf_s("%s\t", stringsArr[i]);
	}
	printf_s("@\n");

	char* anotherString = "Hello, my name is Maksim";
	printf_s("Before replacing substring:\t%s\n", anotherString);
	anotherString = replace(anotherString, "name", "second name");
	anotherString = replace(anotherString, "Maksim", "Petrov");
	anotherString = replace(anotherString, "ello", "i");
	printf_s("After replacing substring:\t%s\n", anotherString);
	free(anotherString);
}