#include "ATM.h"
#include "myString.h"
#include <conio.h>

char* readInfo(char* userId)
{
    FILE* file;
    char* path = (char*)malloc(sizeof(char) * 520);
    char* userInfo = (char*)malloc(sizeof(char) * 400);
    wchar_t CurWorkDir[520];
    int status;
    status = GetCurrentDirectoryW(520, CurWorkDir);
    if (status == 0)
    {
        return "";
    }
    sprintf_s(path, 200, "%ws\\database\\%s.txt", CurWorkDir, userId);
    if (fopen_s(&file, path, "r"))
    {
        errex();
    }
    fgets(userInfo, 400, file);
    fclose(file);
    free(path);
    return userInfo;
}

void newATM(ATM* atm, char*** database, int usersCount)
{
    atm->users = (User*)malloc(sizeof(User) * usersCount);
    for (int i = 0; i < usersCount; i++)
    {
        atm->users[i].cardNumber = (char*)malloc(sizeof(char) * (16 + 1));
        atm->users[i].password = (char*)malloc(sizeof(char) * (8 + 1));
        atm->users[i].phoneNumber = (char*)malloc(sizeof(char) * (11 + 1));

        strncpy(atm->users[i].cardNumber, database[i][0], 16);
        strncpy(atm->users[i].password, database[i][1], 8);
        atm->users[i].account = atoi(database[i][2]);
        strncpy(atm->users[i].phoneNumber, database[i][3], 11);
        atm->users[i].mobileBalance = atoi(database[i][4]);

        atm->users[i].cardNumber[16] = '\0';
        atm->users[i].password[8] = '\0';
        atm->users[i].phoneNumber[11] = '\0';
    }
}



char*** getDataBase(FILE* data)
{
    int linesCount = countLinesInFile(data);
    char*** dataBase = (char***)malloc(sizeof(char**) * linesCount);
    char* buffer = (char*)malloc(sizeof(char) * MAX_STRING_LEN);
    fseek(data, 0, 0);
    for (int i = 0; i < linesCount; i++)
    {
        fgets(buffer, MAX_STRING_LEN, data);
        dataBase[i] = StringToWords(buffer);
    }
    free(buffer);
    fseek(data, 0, 0);
    return dataBase;
}

int authentication(ATM* atm, char* inputCardNumber, char* inputPassword, int usersCount)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (!(strcmp(atm->users[i].cardNumber, inputCardNumber)))
        {
            if (!(strcmp(atm->users[i].password, inputPassword)))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
}

void getCash(ATM* atm, char* userName, int usersCount)
{
    system("cls");
    printf_s("How much do you want to get?\nYour balance is:\t");
    checkBalance(findUser(atm, usersCount, userName));
    int value = 0;
    scanf_s("%d", &value);
    for (int i = 0; i < usersCount; i++)
    {
        if (!(strcmp(atm->users[i].cardNumber, userName)))
        {
            if (atm->users[i].account - value < 0)
            {
                printf_s("You don't have enough money to get from ATM!\n");
                system("pause");
                return;
            }
            atm->users[i].account -= value;
            printf_s("Success!");
            return;
        }
    }
}

int isUserInDataBase(ATM* atm, char* user, int usersCount)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (!(strcmp(atm->users[i].cardNumber, user)))
        {
            return 0;
        }
    }
    return 1;
}

void insertCash(ATM* atm, char* userName, int usersCount)
{
    system("cls");
    printf_s("How much do you want to insert?\n");
    int value = 0;
    scanf_s("%d", &value);
    for (int i = 0; i < usersCount; i++)
    {
        if (!(strcmp(atm->users[i].cardNumber, userName)))
        {
            atm->users[i].account += value;
            printf_s("Success!\n");
            system("pause");
        }
    }
}

void checkBalance(User* user)
{
    printf_s("%d\n", user->account);
}

User* findUser(ATM* atm, int usersCount, char* cardNumber)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (!(strcmp(atm->users[i].cardNumber, cardNumber)))
        {
            return &atm->users[i];
        }
    }
}

void payForMobileCommunication(ATM* atm, char* cardNumber, int usersCount)
{
    system("cls");
    printf_s("Choose the way how will you pay for mobile communication\n");
    printf_s("1. Pay in cash\n2. Pay by card\n");
    char action = _getch();
    system("cls");
    printf_s("How much money do you want to put on your mobile account?\nYour card balance is:\t");
    User* user = findUser(atm, usersCount, cardNumber);
    checkBalance(user);
    int value = 0;
    scanf_s("%d", &value);
    if (user->account - value < 0)
    {
        printf_s("You don't have enough money on your card!\n");
        system("pause");
        return;
    }
    switch (action)
    {
    case '1':
        user->mobileBalance += value;
        printf_s("Success!\n");
        system("pause");
        break;

    case '2':
        user->mobileBalance += value;
        user->account -= value;
        printf_s("Success!\n");
        system("pause");
    }
    return;
}

void writeDataBaseToFile(ATM* atm, int usersCount)
{
    FILE* file;
    if (fopen_s(&file, "dataBase.txt", "w")) errex();
    for (int i = 0; i < usersCount; i++)
    {
        fprintf_s(file, "%s %s %d %s %d\n",
            atm->users[i].cardNumber,
            atm->users[i].password,
            atm->users[i].account,
            atm->users[i].phoneNumber,
            atm->users[i].mobileBalance);
    }
    fclose(file);
}

void encryptPasswords(ATM* atm, int usersCount)
{
    char** passwordsArray = (char**)malloc(sizeof(char*) * usersCount);
    for (int i = 0; i < usersCount; i++)
    {
        passwordsArray[i] = (char*)malloc(sizeof(char) * 8);
    }
    for (int i = 0; i < usersCount; i++)
    {
        strcpy(passwordsArray[i], atm->users[i].password);
    }
    for (int i = 0; i < usersCount; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0)
            {
                passwordsArray[i][j] = (char)((int)(passwordsArray[i][j]) + 13);
            }
            else
            {
                passwordsArray[i][j] = (char)((int)(passwordsArray[i][j]) - 7);
            }
        }
        for (int j = 0; j < strlen(passwordsArray[i]) / 2; j++)
        {
            swap(&passwordsArray[i][j], &passwordsArray[i][j + strlen(passwordsArray[i]) / 2]);
        }
    }
    for (int i = 0; i < usersCount; i++)
    {
        strcpy(atm->users[i].password, passwordsArray[i]);
    }
    free(passwordsArray);
}

char* encryptInputPassword(char* password)
{
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            password[i] = (char)((int)(password[i]) + 13);
        }
        else
        {
            password[i] = (char)((int)(password[i]) - 7);
        }
    }
    for (int i = 0; i < strlen(password) / 2; i++)
    {
        swap(&password[i], &password[i + strlen(password) / 2]);
    }
    return password;
}

void decryptPasswords(ATM* atm, int usersCount)
{
    char** passwordsArray = (char**)malloc(sizeof(char*) * usersCount);
    for (int i = 0; i < usersCount; i++)
    {
        passwordsArray[i] = (char*)malloc(sizeof(char) * 8);
    }
    for (int i = 0; i < usersCount; i++)
    {
        strcpy(passwordsArray[i], atm->users[i].password);
    }
    for (int i = 0; i < usersCount; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0)
            {
                passwordsArray[i][j] = (char)((int)(passwordsArray[i][j]) - 13);
            }
            else
            {
                passwordsArray[i][j] = (char)((int)(passwordsArray[i][j]) + 7);
            }
        }
        for (int j = 0; j < strlen(passwordsArray[i]) / 2; j++)
        {
            swap(&passwordsArray[i][j], &passwordsArray[i][j + strlen(passwordsArray[i]) / 2]);
        }
    }
    for (int i = 0; i < usersCount; i++)
    {
        strcpy(atm->users[i].password, passwordsArray[i]);
    }
    free(passwordsArray);
}