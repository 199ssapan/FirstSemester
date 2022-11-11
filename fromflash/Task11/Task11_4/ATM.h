#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIELDS_COUNT 4

typedef struct User
{
    char* cardNumber;
    char* password;
    int account;
    char* phoneNumber;
}User;

typedef struct ATM
{
    User* users;
}ATM;

char* readInfo(char* userId);
char*** getDataBase(FILE* data);
void newATM(ATM* atm, char*** database, int usersCount);
int authentication(ATM* atm, char* inputCardNumber, char* inputPassword, int usersCount);