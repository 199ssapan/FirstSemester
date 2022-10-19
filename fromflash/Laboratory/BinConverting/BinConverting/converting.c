#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define NUMBER_OF_DIGITS 32
#define MAX_FILE_NAME_SYMBOLS 101
#define MEM_ALL_ERR "MEMORY ALLOCATION ERROR!"

int countingBinDigits(int);
int* createBinaryNumber(int);
void binNumberTransormation(int*, int*, int);
int sumDigitsInNumber(int);

int main()
{

    FILE* input, * output;
    printf_s("Enter an input and output file names\n>");
    char* inputFileName = malloc(MAX_FILE_NAME_SYMBOLS * sizeof(char));
    char* outputFileName = malloc(MAX_FILE_NAME_SYMBOLS * sizeof(char));
    if (!(inputFileName || outputFileName))
    {
        printf_s(MEM_ALL_ERR);
    }
    scanf_s("%s %s", inputFileName, 100, outputFileName, 100);

    if (fopen_s(&input, inputFileName, "r"))
    {
        perror("Input file: ");
        exit(1);
    }
    if (fopen_s(&output, outputFileName, "r+"))
    {
        perror("Output file: ");
        exit(1);
    }

    char* checkString = (char*)malloc(12 * sizeof(char));
    char* intMinString = "-2147483648";
    char* intMaxString = "2147483647";
    if (fgets(checkString, 12, input))
    {
        for (int i = 0; i < strlen(checkString); i++)
        {
            if (!(checkString[i] >= '0' && checkString[i] <= '9') && !(checkString[i] == '-'))
            {
                printf_s("Enter the number correctly!");
                exit(1);
            }
        }
    }
    else
    {
        printf_s("No numbers in input file!");
        exit(1);
    }
    fseek(input, 0, 0);
    if (fgets(checkString, 12, input))
    {
        if (checkString[0] == "-")
        {
            if (strlen(intMinString) < strlen(checkString))
            {
                printf_s("Too small number");
                exit(1);
            }
            else if (strlen(intMinString) == strlen(checkString))
            {
                for (int i = 1; i < strlen(checkString); i++)
                {
                    if (intMinString[i] > checkString[i])
                    {
                        printf_s("Too small number");
                        exit(1);
                    }
                }
            }
        }
        else
        {
            if (strlen(intMaxString) < strlen(checkString))
            {
                printf_s("Too big number");
                exit(1);
            }
            else if (strlen(intMaxString) == strlen(checkString))
            {
                for (int i = 0; i < strlen(checkString); i++)
                {
                    if (intMaxString[i] > checkString[i])
                    {
                        printf_s("Too big number");
                        exit(1);
                    }
                }
            }
        }
    }
    fseek(input, 0, 0);
    int inputDecNumber;
    if (!(fscanf_s(input, "%d", &inputDecNumber)))
    {
        perror("No numbers in input file!");
    }

    int inputDecNumberBackup = inputDecNumber;
    int count = countingBinDigits(inputDecNumber);

    int* binaryNumber = createBinaryNumber(inputDecNumber);
    if (!(binaryNumber))
    {
        printf_s(MEM_ALL_ERR);
    }

    int* digits32BinNumber = (int*)calloc(NUMBER_OF_DIGITS, sizeof(int));
    if (!(digits32BinNumber))
    {
        printf_s(MEM_ALL_ERR);
        exit(1);
    }
    binNumberTransormation(digits32BinNumber, binaryNumber, inputDecNumber);
    free(binaryNumber);
    printf_s("%d\n\n", sumDigitsInNumber(inputDecNumber));
    for (int i = 0; i < NUMBER_OF_DIGITS; i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            printf_s(" ");
        }
        printf_s("%d ", digits32BinNumber[i]);
    }
    for (int i = 0; i < NUMBER_OF_DIGITS; i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            fprintf_s(output, " ");
        }
        fprintf_s(output, "%d", digits32BinNumber[i]);
    }
    free(digits32BinNumber);
    fclose(input);
    fclose(output);
    return 0;
}

int countingBinDigits(int decNumber)
{
    int count = 0;
    decNumber = abs(decNumber);
    while (decNumber != 0)
    {
        decNumber /= 2;
        count++;
    }
    return count;
}

int* createBinaryNumber(int decNumber)
{
    int absDecNumber = abs(decNumber);
    int binDigitsCount = countingBinDigits(decNumber);
    int* binaryArray = (int*)calloc(binDigitsCount, sizeof(int));
    if (!(binaryArray))
    {
        printf_s(MEM_ALL_ERR);
        exit(1);
    }
    for (int i = binDigitsCount - 1; i >= 0; i--)
    {
        if (absDecNumber % 2 == 0)
        {
            binaryArray[i] = 0;
        }
        else
        {
            binaryArray[i] = 1;
        }
        absDecNumber /= 2;
    }
    return binaryArray;
}

void binNumberTransormation(int* finalBinNumber, int* binNumber, int decNumber)
{
    int count = countingBinDigits(decNumber);
    for (int i = 0; i < count; i++)
    {
        finalBinNumber[i + NUMBER_OF_DIGITS - count] = binNumber[i];
    }

    if (decNumber < 0)
    {
        for (int i = 0; i < NUMBER_OF_DIGITS; i++)
        {
            if (finalBinNumber[i] == 0)
            {
                finalBinNumber[i] = 1;
            }
            else
            {
                finalBinNumber[i] = 0;
            }
        }

        for (int i = NUMBER_OF_DIGITS - 1; i >= 0; i--)
        {
            if (finalBinNumber[i] == 0)
            {
                finalBinNumber[i] = 1;
                break;
            }
            else
            {
                finalBinNumber[i] = 0;
            }
        }
    }
}

int sumDigitsInNumber(int number)
{
    int sum = 0;
    int lastDigit = 0;
    while (number != 0)
    {
        sum += (number % 10);
        number /= 10;
    }
    return abs(sum);
}