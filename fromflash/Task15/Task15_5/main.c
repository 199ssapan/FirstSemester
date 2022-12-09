#include "instr.h"

int main()
{
	COORD p;
	p.X = 4;
	p.Y = 4;
	SetFontSize(GetStdHandle(STD_OUTPUT_HANDLE), p);
	setconsolesize(140, 140);
	for (int x = 0; x < 128; x++)
	{
		for (int y = 0; y < 128; y++)
		{
			gotoxy(x, y);
			if ((x & y) == 0) printf_s("#");
			Sleep(0.5);
		}
	}
	return 0;
}