#include "ATM.h"
#include "myString.h"

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
        if (!strcmp(atm->users[i].cardNumber, inputCardNumber))
        {
            if (!strcmp(atm->users[i].password, inputPassword))
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