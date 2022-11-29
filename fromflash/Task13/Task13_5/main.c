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
	printList(list);
	return 0;
}