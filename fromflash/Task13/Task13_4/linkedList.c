#include "linkedList.h"

linkedList* initlinkedList()
{
	linkedList* list = (linkedList*)malloc(sizeof(linkedList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void pushBack(linkedList* list, char* value)
{
	Node* newElem = (Node*)malloc(sizeof(Node));
	newElem->Data = (char*)malloc(MAX_STR_LEN * sizeof(char));
	strcpy(newElem->Data, value);
	newElem->next = 0;
	if (list->tail != NULL) list->tail->next = newElem;
	list->tail = newElem;
	if (list->head == 0) list->head = newElem;
	list->size++;
}

Node* findElemByValue(linkedList* list, char* value)
{
	Node* current = NULL;
	if (list->head != 0)
	{
		current = list->head;
		while (current != NULL)
		{
			if (!strcmp(current->Data, value))
			{
				break;
			}
			current = current->next;
		}
	}
	return current;
}

int deleteElement(linkedList* list, char* value)
{
	Node* current = NULL;
	Node* previous = NULL;
	if (list->head == 0)
	{
		return 0;
	}
	current = list->head;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			previous = current;
			current = current->next;
			if (!strcmp(current->Data, value))
			{
				previous->next = current->next;
				free(current->Data);
				free(current);
				break;
			}
		}
	}
	list->size--;
	return 1;
}

int getSizeOfList(linkedList* list)
{
	return list->size;
}

void printList(linkedList* list)
{
	Node* current = NULL;
	if (list->head == 0)
	{
		printf_s("This list is empty!\n");
		return;
	}
	current = list->head;
	while (current != NULL)
	{
		printf_s("%s\t", current->Data);
		current = current->next;
	}
}

Node* findElemByPosition(linkedList* list, int position)
{
	Node* current = NULL;
	if (list->head == NULL)
	{
		return NULL;
	}
	else if (position > list->size - 1)
	{
		return NULL;
	}
	current = list->head;
	for (int i = 0; i < position; i++)
	{
		current = current->next;
	}
	return current;
}

int destroyList(linkedList* list)
{
	Node* current = NULL;
	Node* previous = NULL;
	if (list->head == 0)
	{
		return 1;
	}
	current = list->head;
	while (current != NULL)
	{
		free(current->Data);
		previous = current;
		current = current->next;
		free(previous);
	}
	free(list);
	return 1;
}