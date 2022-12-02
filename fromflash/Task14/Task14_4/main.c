#include "list.h"
#include "myString.h"

void s_copy(char** d, char** s);
void s_swap(char** f, char** s);
void i_swap(int* f, int* s);

//доделать!!!!!!!!!!!!
int main(int argc, char* argv[])
{
	List* list1 = createList();
	for (int i = 2; i < argc; i++)
	{
		pushBack(list1, argv[i]);
	}
	int* lenArr = (int*)malloc(sizeof(int) * (argc - 2));
	char** stringsArr = (char**)malloc(sizeof(char*) * (argc - 2));
	for (int i = 2; i < argc; i++)
	{
		stringsArr[i] = (char*)malloc(sizeof(char) * MAX_STR_LEN);
	}
	for (int i = 2; i < argc; i++)
	{
		s_copy(&stringsArr[i - 2], &argv[i]);
	}
	for (int i = 0; i < argc - 2; i++)
	{
		printf_s("%s ", stringsArr[i]);
	}
	for (int i = 2; i < argc; i++)
	{
		lenArr[i - 2] = strlen(argv[i]);
	}
	for (int i = 0; i < argc - 2; i++)
	{
		for (int j = 0; j < argc - 3; j++)
		{
			if (lenArr[j] < lenArr[j + 1])
			{
				i_swap(&lenArr[j], &lenArr[j + 1]);
				s_swap(&stringsArr[j], &stringsArr[j + 1]);
			}
		}
	}
	List* list = createList();
	for (int i = 0; i < argc - 2; i++)
	{
		pushBack(list, stringsArr[i]);
	}
	for (int i = atoi(argv[1]); i < argc; i++)
	{
		Node* elem = findElemByPosition(list, i);
		deleteElem(list1, elem->data);
	}
	printList(list1);
	return 0;
}

void s_copy(char** dest, char** src)
{
	*dest = *src;
}

void s_swap(char** f, char** s)
{
	char* tmp = *f;
	*f = *s;
	*s = tmp;
}

void i_swap(int* f, int* s)
{
	int tmp = *f;
	*f = *s;
	*s = tmp;
}