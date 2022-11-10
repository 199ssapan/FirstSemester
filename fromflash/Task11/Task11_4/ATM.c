#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIELDS_COUNT 4
#define MAX_CLIENTS_COUNT 10
#define MAX_STRING_LEN 150
typedef struct ATM
{
	char** phones;
	char** passwords;
	char** cardsNumbers;
	char** accounts;
}ATM;
int main()
{
	
}

int mainMenu()
{

}

ATM newATM(FILE* database)
{
	ATM atm;
	atm.phones = (char**)malloc(MAX_CLIENTS_COUNT * sizeof(char*));
	atm.passwords = (char**)malloc(MAX_CLIENTS_COUNT * sizeof(char*));
	atm.cardsNumbers = (char**)malloc(MAX_CLIENTS_COUNT * sizeof(char*));
	atm.accounts = (char**)malloc(MAX_CLIENTS_COUNT * sizeof(char*));
}

