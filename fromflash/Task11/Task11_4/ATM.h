#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define FIELDS_COUNT 5

typedef struct User
{
    char* cardNumber;
    char* password;
    int account;
    char* phoneNumber;
    int mobileBalance;
}User;

typedef struct ATM
{
    User* users;
}ATM;

char* readInfo(char* userId);
char*** getDataBase(FILE* data);
void newATM(ATM* atm, char*** database, int usersCount);
int authentication(ATM* atm, char* inputCardNumber, char* inputPassword, int usersCount);
int isUserInDataBase(ATM* atm, char* user, int usersCount);
int getCash(ATM* atm, char* userName, int usersCount);
void insertCash(ATM* atm, char* userName, int usersCount);
void checkBalance(User* user);
User* findUser(ATM* atm, int usersCount, char* cardNumber);
int payForMobileCommunication(ATM* atm, char* cardNumber, int usersCount);
void writeDataBaseToFile(ATM* atm, int usersCount);
