#include "list.h"

int main()
{
	List* list = createList();
	pushFront(list, "Hello");
	pushFront(list, "world");
	pushFront(list, "Vorld");
	pushFront(list, "BArld");
	pushFront(list, "Jarld");
	pushFront(list, "Ad");
	pushFront(list, "Ax");

	printList(list);
	bubbleSorting(list);
	pushBack(list, "word");
	pushBack(list, "AABB");
	pushBack(list, "CCDD");
	pushBack(list, "189");
	pushFront(list, "_");
	printList(list);
	bubbleSorting(list);
	printList(list);
	destroyList(list);
	return 0;
}