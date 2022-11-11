#include "myString.h"
#include "ATM.h"

int main()
{
	FILE* data;
	ATM atm;
	if (fopen_s(&data, "dataBase.txt", "r")) errex();
	int usersCount = countLinesInFile(data);
	char*** dataBase = getDataBase(data);
	newATM(&atm, dataBase, usersCount);
	return 0;
}

int mainMenu(ATM* atm, FILE* file)
{
	system("cls");
	printf_s("Enter a card number and your password");
	char* cardNumber = (char*)malloc(sizeof(char) * (16 + 1));
	char* password = (char*)malloc(sizeof(char) * (8 + 1));
	scanf_s("%s %s", cardNumber, 16, password, 8);
	if (cardNumber && password)
	{
		cardNumber[16] = '\0';
		password[8] = '\0';
	}
	int usersCount = countLinesInFile(file);
	if (authentication(atm, cardNumber, password, usersCount))
	{
		//not completed!!!!!!!!
	}

	
}