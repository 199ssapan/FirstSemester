#pragma once
#define ELEMS_IN_STORAGE 5
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagStack
{
    int top;
    Point* storage;
}Stack;

void stackNew(Stack* s);
int push(Stack*);
int pop(Stack* stack);
int showTheTop(Stack* stack);
int deleteStack(Stack* stack);
