#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "set_ui.h"

int menu_ui(char* game_name, int menu, char* menu1, char* menu2, char* menu3, char* menu4)
{
	int i;
	system("mode con cols=78 lines=21");

	for (i = 0; i < 39; i++)
	{
		gotoxy(i, 0); printf("бс");
		gotoxy(i, 20); printf("бс");
	}
	for (i = 1; i < 20; i++)
	{
		gotoxy(0, i); printf("бс");
		gotoxy(38, i); printf("бс");
	}

	gotoxy(15, 5); printf("в╠");
	gotoxy(19 - (strlen(game_name))/4, 5); printf("%s", game_name);
	gotoxy(22, 5); printf("в╠");
	gotoxy(19 - (strlen(menu1)) / 4, 10); printf("%s", menu1);
	gotoxy(19 - (strlen(menu2)) / 4, 12); printf("%s", menu2);
	gotoxy(19 - (strlen(menu3)) / 4, 14); printf("%s", menu3);
	gotoxy(19 - (strlen(menu4)) / 4, 16); printf("%s", menu4);

	int key = 0, cursor = 1;

	while (1)
	{
		for (i = 0; i < 7; i += 2)
		{
			gotoxy(16, 10 + i); printf(" ");
			gotoxy(21, 10 + i); printf("  ");
		}

		gotoxy(16, 10 + 2 * (cursor - 1)); printf(">");
		gotoxy(21, 10 + 2 * (cursor - 1)); printf(" <");

		key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == 80 || key == 77)
			{
				cursor++;
			}
			else if (key == 72 || key == 75)
			{
				cursor--;
			}
		}
		else
		{
			if (key == 13)
				break;
		}

		if (cursor == menu + 1)
		{
			cursor = 1;
		}

		if (cursor == 0)
		{
			cursor = 3;
		}
	}
	return cursor;
}


