#include "list.h"

int main()
{
	List* list = createList();
	pushFront(list, "Hello");
	pushFront(list, "world");
	pushFront(list, "my");
	pushFront(list, "name");
	pushFront(list, "is");
	pushFront(list, "Maksim");

	deleteElem(list, "world");

	pushBack(list, "How");
	pushBack(list, "are");
	pushBack(list, "you");

	printList(list);

	deleteElem(list, "d");
	deleteElem(list, "Maksim");

	printList(list);

	deleteElem(list, "you");

	printList(list);

	deleteElem(list, "is");
	printList(list);
	destroyList(list);
	return 0;
}