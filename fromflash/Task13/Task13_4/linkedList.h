#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 150

typedef struct
{
	char* Data;
	struct Node* next;
}Node;

typedef struct
{
	Node* head;
	Node* tail;
	unsigned size;
}linkedList;

linkedList* initlinkedList();
void pushBack(linkedList* list, char* value);
Node* findElemByValue(linkedList* list, char* value);
int deleteElement(linkedList* list, char* value);
int getSizeOfList(linkedList* list);
void printList(linkedList* list);
Node* findElemByPosition(linkedList* list, int position);
int destroyList(linkedList* list);
