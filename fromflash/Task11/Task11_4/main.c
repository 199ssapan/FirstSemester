#include "myString.h"
#include "ATM.h"
int mainMenu(ATM* atm, FILE* file);

int main()
{
	FILE* data;
	ATM atm;
	if (fopen_s(&data, "dataBase.txt", "r")) errex();
	int usersCount = countLinesInFile(data);
	char*** dataBase = getDataBase(data);
	newATM(&atm, dataBase, usersCount);
	while (mainMenu(&atm, data)) {};
	fclose(data);
	writeDataBaseToFile(&atm, usersCount);
	return 0;
}

int mainMenu(ATM* atm, FILE* file)
{
	system("cls");
	
	char* cardNumber = (char*)malloc(sizeof(char) * (16 + 1));
	char* password = (char*)malloc(sizeof(char) * (8 + 1));
	printf_s("Enter a card number\n");
	gets_s(cardNumber, 16 + 1);
	int usersCount = countLinesInFile(file);
	if (isUserInDataBase(atm, cardNumber, usersCount))
	{
		printf_s("No such user in database\n");
		system("pause");
		return 1;
	}
	printf_s("Enter your password\n");
	gets_s(password, 8 + 1);
	if (authentication(atm, cardNumber, password, usersCount))
	{
		printf_s("Uncorrect Password");
		system("pause");
		return 1;
	}
	system("cls");
	printf_s("Password is correct, choose the option\n");
	printf_s("1. Get cash\n2. Insert cash\n3. Pay for mobile communication\n4. Exit\n");
	char action = _getch();
	switch (action)
	{
		case '1':
			if (getCash(atm, cardNumber, usersCount)) return 1;
			break;
		case '2':
			insertCash(atm, cardNumber, usersCount);
			break;
		case '3':
			if (payForMobileCommunication(atm, cardNumber, usersCount)) return 1;
			break;
		case '4':
			return 0;
		default:
			printf_s("Wrong command!\n");
			return 1;
	}
	free(cardNumber);
	free(password);
	scanf("%c", (char*)stdin);
	return 1;
}