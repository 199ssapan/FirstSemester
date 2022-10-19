#include <stdio.h>
#include <stdlib.h>

#define A -100
#define B 100
#define M 5
#define N 5

void printArr(int arr[N])
{
    for (int i = 0; i < N; i++)
    {
        printf_s("%d ", arr[i]);
    }
    printf_s("\n\n");
}

int main()
{
    int arr[N][M];
    srand((unsigned)time(0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int rand_num = rand() % (B - A + 1) + A;
            arr[i][j] = rand_num;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < M - 1; k++)
            {
                int tmp;
                if (arr[i][k] > arr[i][k + 1])
                {
                    tmp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = tmp;
                }
            }
        }
    }
    int firstElemsArr[N];
    int indexArr[N];
    for (int i = 0; i < N; i++)
    {
        firstElemsArr[i] = arr[i][0];
    }
    for (int i = 0; i < N; i++)
    {
        indexArr[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            int tmp;
            if (firstElemsArr[j] > firstElemsArr[j + 1])
            {
                tmp = firstElemsArr[j + 1];
                firstElemsArr[j + 1] = firstElemsArr[j];
                firstElemsArr[j] = tmp;

                tmp = indexArr[j + 1];
                indexArr[j + 1] = indexArr[j];
                indexArr[j] = tmp;
            }
        }
    }
    int* ptrArr[N];
    for (int i = 0; i < M; i++)
    {
        //arr[0][1] == *(arr[0] + 1)
        //int *ptr == &arr[0] == arr
        //*arr[  indexArr[i]  ] == *(arr + index[i]])
        ptrArr[i] = (arr[indexArr[i]]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf_s("%d   ", arr[i][j]);
        }
        printf_s("\n");
    }
    printf_s("\n");
    printf_s("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf_s("%d   ", ptrArr[i][j]);
        }
        printf_s("\n");
    }
    printf_s("\n\n");
    printArr(indexArr);


    return 0;
}
