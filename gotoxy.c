#include <Windows.h>
#include "set_ui.h"

void gotoxy(int x, int y)
{
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}