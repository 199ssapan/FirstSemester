#include "stack.h"


void stackNew(Stack* stack)
{
    stack->storage = (Point*)calloc(ELEMS_IN_STORAGE, sizeof(Point));
}
int push(Stack* stack)
{
    if (stack->top == ELEMS_IN_STORAGE)
    {
        printf_s("There is no free storage space!\n");
        system("pause");
        return 1;
    }
    printf_s("Enter the 'x' and 'y'");
    Point point;
    scanf_s("%d %d", &point.x, &point.y);
    stack->storage[stack->top] = point;
    stack->top++;
    return 0;
}

int pop(Stack* stack)
{
    if (stack->top == 0)
    {
        printf_s("There is no data to delete!\n");
        system("pause");
        return 1;
    }
    Point p;
    p.x = 0;
    p.y = 0;
    stack->storage[stack->top - 1] = p;
    printf_s("You has succesfully deleted the element!\n");
    system("pause");
    stack->top--;
    return 0;
}
int showTheTop(Stack* stack)
{
    if (stack->top == 0)
    {
        printf_s("There is no data in storage\n");
        system("pause");
        return 1;
    }
    printf_s("x: %d  y: %d\n", stack->storage[stack->top - 1].x, stack->storage[stack->top - 1].y);
    system("pause");
    return 0;
}

int deleteStack(Stack* stack)
{
    free(stack->storage);
    return 0;
}
