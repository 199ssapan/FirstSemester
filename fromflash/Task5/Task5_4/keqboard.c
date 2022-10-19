#include <stdio.h>
#include <stdlib.h>

#define MAX_BUTTONS 100
#define FILE_NAME "new-keyboard.txt"
int countingBrokenButtons(int frequency[MAX_BUTTONS], int strength[MAX_BUTTONS], int buttons_count)
{
    int broken_buttons = 0;
    for (int i = 0; i < buttons_count; i++)
    {
        if (frequency[i] > strength[i])
        {
            broken_buttons++;
        }
    }
    return broken_buttons;
}
void strengthLeft(int frequencyArray[MAX_BUTTONS], int strengthArray[MAX_BUTTONS], int buttonsCount)
{
    int strengthLeftArray[MAX_BUTTONS];
    for (int i = 0; i < buttonsCount; i++)
    {
        strengthLeftArray[i] = strengthArray[i] - frequencyArray[i];
    }
    int index[MAX_BUTTONS];
    for (int i = 0; i < buttonsCount; i++)
    {
        index[i] = i + 1;
    }
    int tmp;
    for (int i = 0; i < buttonsCount; i++)
    {
        for (int j = 1; j < buttonsCount; j++)
        {
            if (strengthLeftArray[j - 1] < strengthLeftArray[j])
            {
                tmp = strengthLeftArray[j - 1];
                strengthLeftArray[j - 1] = strengthLeftArray[j];
                strengthLeftArray[j] = tmp;

                tmp = index[j - 1];
                index[j - 1] = index[j];
                index[j] = tmp;
            }
        }

    }
    for (int i = 0; i < buttonsCount; i++)
    {
        printf_s("%d ", index[i]);
    }
}
int main()
{
    FILE* input;
    if (fopen_s(&input, FILE_NAME, "r"))
    {
        exit(1);
    }
    int buttonsCount;
    int strengthArray[MAX_BUTTONS] = { 0 };
    fscanf_s(input, "%d", &buttonsCount);
    for (int i = 0; i < buttonsCount; i++)
    {
        fscanf_s(input, "%d", &strengthArray[i]);
    }
    int frequencyArray[MAX_BUTTONS] = { 0 };
    int buffer;
    while (fscanf_s(input, "%d", &buffer) != EOF)
    {
        frequencyArray[buffer - 1]++;
    }
    int brokenButtons = countingBrokenButtons(frequencyArray, strengthArray, buttonsCount);
    printf_s("%d\n", brokenButtons);
    strengthLeft(frequencyArray, strengthArray, buttonsCount);
    return 0;
}