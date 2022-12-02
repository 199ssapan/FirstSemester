#include "list.h"

List* createList()
{
	List* list = (List*)malloc(sizeof(List));
	if (list)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
	return list;
}

void pushBack(List* list, char* value)
{
	Node* newElem = (Node*)malloc(sizeof(Node));
	newElem->data = (char*)malloc(sizeof(char) * MAX_STR_LEN);
	if (newElem)
	{
		strcpy(newElem->data, value);
		newElem->next = NULL;
		newElem->prev = NULL;

		if (list->head == NULL)
			list->head = newElem;
		else if (list->tail == NULL)
		{
			list->tail = newElem;
			list->tail->prev = list->head;
			list->head->next = list->tail;
		}
		else
		{
			list->tail->next = newElem;
			newElem->prev = list->tail;
			list->tail = newElem;
		}
		list->size++;
	}
}

void pushFront(List* list, char* value)
{
	Node* newElem = (Node*)malloc(sizeof(Node));
	newElem->data = (char*)malloc(sizeof(char) * MAX_STR_LEN);
	strcpy(newElem->data, value);
	newElem->next = list->head;
	newElem->prev = NULL;
	if (list->head != NULL)
	{
		list->head->prev = newElem;
	}
	list->head = newElem;

	if (list->tail == NULL)
	{
		list->tail = newElem;
	}

	list->size++;
}

void deleteElem(List* list, char* value)
{
	Node* current = list->head;
	if (!current)
	{
		printf_s("No elements in list!\n");
		return;
	}
	if (!strcmp(current->data, value))
	{
		list->head = current->next;
		free(list->head->prev->data);
		free(list->head->prev);
		list->size--;
		return;
	}
	current = current->next;
	while (current->next != NULL)
	{
		if (!strcmp(current->data, value))
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
			free(current->data);
			free(current);
			list->size--;
			return;
		}
		current = current->next;
	}
	if (!strcmp(current->data, value))
	{
		list->tail = current->prev;
		free(list->tail->next->data);
		free(list->tail->next);
		list->tail->next = NULL;
		list->size--;
		return;
	}
	printf_s("No such element in the list!\n");
	return;
}

void printList(List* list)
{
	Node* current;
	current = list->head;
	while (current != NULL)
	{
		if (current == list->tail)
		{
			printf_s("%s\n", current->data);
		}
		else
		{
			printf_s("%s ", current->data);
		}
		current = current->next;
	}
}

Node* findElemByValue(List* list, char* value)
{
	Node* current = NULL;
	if (list->head != 0)
	{
		current = list->head;
		while (current != NULL)
		{
			if (!strcmp(current->data, value))
			{
				break;
			}
			current = current->next;
		}
	}
	return current;
}

Node* findElemByPosition(List* list, int position)
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

unsigned getSizeOfList(List* list)
{
	return list->size;
}

void destroyList(List* list)
{
	Node* current = NULL;
	Node* previous = NULL;
	if (list->head == NULL)
	{
		return;
	}
	current = list->head;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous->data);
		free(previous);
	}
	free(list);
}

void swapNeighbourNodes(Node* lNode, Node* rNode)
{
	if (lNode == NULL || rNode == NULL)
	{
		printf_s("NULL nodes!\n");
		return;
	}
	Node* leftPrev = lNode->prev;
	Node* rightNext = rNode->next;
	if (leftPrev != NULL)
	{
		leftPrev->next = rNode;
	}
	if (rightNext != NULL)
	{
		rightNext->prev = lNode;
	}
	rNode->prev = leftPrev;
	lNode->next = rightNext;
	lNode->prev = rNode;
	rNode->next = lNode;
}

void safetySwap(List* list, Node* leftNode, Node* rightNode)
{
	if (leftNode == rightNode)
	{
		return;
	}
	if (rightNode->next == leftNode)
	{
		swapNeighbourNodes(rightNode, leftNode);
	}
	else if (leftNode->next == rightNode)
	{
		swapNeighbourNodes(leftNode, rightNode);
	}
	else
	{
		Node* leftNext = leftNode->next;
		Node* leftPrev = leftNode->prev;
		Node* rightNext = rightNode->next;
		Node* rightPrev = rightNode->prev;

		if (leftPrev != NULL)
			leftPrev->next = rightNode;
		rightNode->prev = leftPrev;
		rightNode->next = leftNext;
		if (leftNext != NULL)
			leftNext->prev = rightNode;

		if (rightPrev != NULL)
			rightPrev->next = leftNode;
		leftNode->next = rightNext;
		leftNode->prev = rightPrev;
		if (rightNext != NULL)
			rightNext->prev = leftNode;
	}
	if (leftNode == list->head)
		list->head = rightNode;
	else if (rightNode == list->head)
		list->head = leftNode;
	if (leftNode == list->tail)
		list->tail = rightNode;
	else if (rightNode == list->tail)
		list->tail = leftNode;
}

void bubbleSorting(List* list)
{
	for (int i = 0; i < list->size; i++)
	{
		Node* current = list->head;
		while (current != NULL)
		{
			if (current->next != NULL)
			{
				if (strcmp(current->data, current->next->data) > 0)
				{
					safetySwap(list, current, current->next);
				}
				else
				{
					current = current->next;
				}
			}
			else
			{
				break;
			}

		}
	}
}