#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARR_ROWS 4
#define ARR_COLUMNS 5

int main()
{
    srand((unsigned)time(0));
    int multidimArr[ARR_ROWS][ARR_COLUMNS];
    for (int i = 0; i < ARR_ROWS; i++)
    {
        for (int j = 0; j < ARR_COLUMNS; j++)
        {
            multidimArr[i][j] = (rand() % 2 ? 1 : -1) * (rand() % 100);
        }
    }
    for (int i = 0; i < ARR_ROWS; i++)
    {
        for (int j = 0; j < ARR_COLUMNS; j++)
        {
            printf_s("%d ", multidimArr[i][j]);
        }
        printf_s("\n");
    }
    printf_s("Enter the number\n");
    int n;
    scanf_s("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = (rand() % 2 ? 1 : -1) * (rand() % (n + n + 1) - n);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf_s("%d ", arr[i]);
    }
    free(arr);
}
