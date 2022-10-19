#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int main() {
    int arr[ARRAY_SIZE];
    // заполнение массива случайными целыми числами из промежутка (-100, 100):
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr[i] = (rand() % 2 ? -1 : 1) * (rand() % 100);
    }
    int number;
    int divisible = 0, notDivisible = 0;
    printf_s("Enter the number\n");
    scanf_s("%d", &number);
    //counting elements for two arrays
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i] % number == 0)
            divisible++;
        else
            notDivisible++;
    }

    int multArr[ARRAY_SIZE];
    int notMultArr[ARRAY_SIZE];
    int iNew = 0, jNew = 0;

    //packaging from original array to the first array
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i] % number == 0)
        {
            multArr[iNew] = arr[i];
            iNew++;
        }
        else
        {
            notMultArr[jNew] = arr[i];
            jNew++;
        }
    }
    int buffer = 0;
    for (int i = 0; i < divisible; i++)
    {
        for (int j = 1; j < divisible; j++)
        {
            if (multArr[j] > multArr[j - 1])
            {
                buffer = multArr[j];
                multArr[j] = multArr[j - 1];
                multArr[j - 1] = buffer;
            }
        }
    }
    for (int i = 0; i < notDivisible; i++)
    {
        for (int j = 1; j < notDivisible; j++)
        {
            if (notMultArr[j] > notMultArr[j - 1])
            {
                buffer = notMultArr[j];
                notMultArr[j] = notMultArr[j - 1];
                notMultArr[j - 1] = buffer;
            }
        }
    }
    printf_s("First array:\n");
    for (int i = 0; i < divisible; i++)
    {
        printf_s("%d ", multArr[i]);
    }
    printf_s("\n");
    printf_s("\n");
    printf_s("Second array:\n");
    for (int i = 0; i < notDivisible; i++)
    {
        printf_s("%d ", notMultArr[i]);
    }
    //collecting all elements to one array
    int firstArrCounter = 0, secondArrCounter = 0;
    int newArr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (firstArrCounter <= divisible && secondArrCounter <= notDivisible)
        {
            newArr[i] = max(multArr[firstArrCounter], notMultArr[secondArrCounter]);
            if (newArr[i] == multArr[firstArrCounter])
                firstArrCounter++;
            if (newArr[i] == notMultArr[secondArrCounter])
                secondArrCounter++;
        }
        else
        {
            if (firstArrCounter > divisible)
            {
                newArr[i] = notMultArr[secondArrCounter];
                secondArrCounter++;
            }
            else if (secondArrCounter > notDivisible)
            {
                newArr[i] = multArr[firstArrCounter];
                firstArrCounter++;
            }
        }
    }
    printf_s("\n");
    printf_s("\n");
    printf("Final array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf_s("%d ", newArr[i]);
    }
    system("pause");
    return 0;
}