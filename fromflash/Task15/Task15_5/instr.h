#pragma once
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void setconsolesize(int x, int y);

void hidecursor();

void clrscr();

void gotoxy(int column, int row);

int GetFontSize(HANDLE windowHandle, COORD* size);

int SetFontSize(HANDLE windowHandle, COORD size);