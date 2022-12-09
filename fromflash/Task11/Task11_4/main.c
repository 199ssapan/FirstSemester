#include "myString.h"
#include "ATM.h"
#include "mainMenu.h"

int main()
{
	FILE* data;
	ATM atm;
	if (fopen_s(&data, "dataBase.txt", "r")) errex();
	int usersCount = countLinesInFile(data);
	char*** dataBase = getDataBase(data);
	newATM(&atm, dataBase, usersCount);
	while (mainMenu(&atm, data, usersCount)) {};
	fclose(data);
	writeDataBaseToFile(&atm, usersCount);
	return 0;
}

