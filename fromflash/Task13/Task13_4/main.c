#include "linkedList.h"

void test(linkedList* list);

int main()
{
	linkedList* list = initlinkedList();
	test(list);
	return 0;
}

void test(linkedList* list)
{
	pushBack(list, "Hello");
	pushBack(list, "world");
	pushBack(list, "my");
	pushBack(list, "name");
	pushBack(list, "is");
	pushBack(list, "Maksim");
	printList(list);
	deleteElement(list, "name");
	printList(list);
	if (!deleteElement(list, "ppp")) printf_s("No such element to delete\n");
	printf_s("\n");

	Node* node = findElemByPosition(list, 5);
	if (node) printf_s("%s\n", node->Data);
	else printf_s("No such element in list!\n");

	Node* node1 = findElemByValue(list, "world");
	if (node1) printf_s("%s\n", node1->Data);
	else printf_s("No such element in list!\n");

	if (!deleteElement(list, "my")) printf_s("No such element to delete\n");
	printList(list);
	printf_s("\n");
	printf_s("%d", getSizeOfList(list));
	destroyList(list);

}