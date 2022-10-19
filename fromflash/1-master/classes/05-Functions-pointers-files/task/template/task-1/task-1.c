#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100
#define INPUT_FILE_NAME "numbers.txt"
#define OUTPUT_FILE_NAME "sorted.txt"

void sort(int[MAX_ARRAY_SIZE], int numbersCount);

int main(void) 
{
    srand((unsigned)time(0));

    FILE* input, * output;

    int arr[MAX_ARRAY_SIZE];

    if (fopen_s(&input, INPUT_FILE_NAME, "w") || fopen_s(&output, OUTPUT_FILE_NAME, "w"))
    {
        exit(1);
    }

    int num;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        num = (rand() % 2 ? 1 : -1) * (rand() % 100);
        fprintf_s(input, "%d ", num);
    }
    fclose(input);
    if (fopen_s(&input, INPUT_FILE_NAME, "r"))
    {
        exit(1);
    }
    int tmp;

    for (int i = 0;i < MAX_ARRAY_SIZE; i++)
    {
        fscanf_s(input, "%d ", &tmp);
        arr[i] = tmp;
    }

    int numCount = MAX_ARRAY_SIZE;
    sort(arr, numCount);

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        fprintf_s(output, "%d ", arr[i]);
    }

    system("pause");
    return 0;
}

void sort(int arr[MAX_ARRAY_SIZE], int numbersCount)
{
    int buffer;
    for (int j = 0; j < numbersCount; ++j)
    {
        for (int i = 1; i < numbersCount; ++i)
        {
            if (arr[i] < arr[i - 1])
            {
                buffer = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = buffer;
            }
        }
    }

}

