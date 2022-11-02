#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"



int mainMenu(Stack* stack);

int main()
{
    Stack stack;
    stack.top = 0;
    stackNew(&stack);
    while (mainMenu(&stack));
    return 0;
}


int mainMenu(Stack* stack)
{
    system("cls");
    printf_s("This programm used for storing your data, exactly dots in the coordinates system\n");
    printf_s("Choose the action\n");
    printf_s("1. Add point\n");
    printf_s("2. Delete point\n");
    printf_s("3. Show the top\n");
    printf_s("4. Exit\n");
    char action = _getch();
    switch (action)
    {
        case '1':
            push(stack);
            break;
        case '2':
            pop(stack);
                break;
        case '3':
            showTheTop(stack);
            break;
        case '4':
            deleteStack(stack);
            return 0;
            break;
        default:
            return 0;
    }
    return 1;

}