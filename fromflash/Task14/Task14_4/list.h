#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 150

struct Node
{
	struct Node* prev;
	char* data;
	struct Node* next;
};

typedef struct Node Node;

typedef struct
{
	Node* head;
	Node* tail;
	unsigned size;
}List;


List* createList();
void pushBack(List* list, char* value);
void pushFront(List* list, char* value);
void deleteElem(List* list, char* value);
void printList(List* list);
Node* findElemByPosition(List* list, int position);
Node* findElemByValue(List* list, char* value);
unsigned getSizeOfList(List* list);
void destroyList(List* list);
void swapNeighbourNodes(Node* lNode, Node* rNode);
void safetySwap(List* list, Node* leftNode, Node* rightNode);
void bubbleSorting(List* list);
