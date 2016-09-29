#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

//-32 72  -32 80

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define WALLX 16
#define WALLY 20

typedef struct _DDONG
{

	int x;
	int y;
	int life;

}DDONG;

DDONG ddong[30] = { 0, 0, 0 };

void IsMove(int *x)
{
	if (WALLX - 1 == *x)
	{
		*x -= 1;
	}
	else if (0 == *x)
	{
		*x += 1;
	}

}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int DDong()
{

	int map[WALLY][WALLX] = { 0 };
	int i, j;
	int c_x = WALLX / 2;
	int c_y = WALLY - 2;


	for (i = 0; i < WALLY; i++)
	{
		for (j = 0; j < WALLX; j++)
		{
			if (0 == j || WALLX - 1 == j || WALLY - 1 == i)
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}

	srand(time(NULL));

	for (i = 0; i < 30; i++)
	{
		if (i < 7)
		{
			ddong[i].life = 1;
		}
		ddong[i].x = rand() % (WALLX - 2) + 1;
		ddong[i].y = 0;
	}


	char ch;

	for (i = 0; i < WALLY; i++)
	{
		for (j = 0; j < WALLX; j++)
		{
			if (1 == map[i][j])
			{
				printf("▒");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	int cnt = 0;
	gotoxy(c_x * 2, c_y);
	printf("☆");

	while (1)
	{
		//gotoxy(0, 0);

		Sleep(100);
		for (i = 0; i < 30; i++)
		{
			if (1 == ddong[i].life)
			{
				//=====================================
				gotoxy(ddong[i].x * 2, ddong[i].y);
				printf("  ");
				ddong[i].y += 1;
				//=====================================

				if (WALLY - 1 == ddong[i].y)
				{
					ddong[i].y = 0;
					ddong[i].life = 0;
					ddong[i].x = rand() % (WALLX - 2) + 1;

					cnt++;
				}
				else if (ddong[i].x == c_x && ddong[i].y == c_y)
				{
					system("cls");
					printf("게임 오버 \n피한갯수 %d\n", cnt);
					return;
				}

				//=====================================
				gotoxy(ddong[i].x * 2, ddong[i].y);
				printf("♨");
				//=====================================
			}
			else
			{
				if (4 == rand() % 10)
				{
					ddong[i].life = 1;
				}
			}
		}

		if (_kbhit())
		{
			ch = getch();
			if (-32 == ch)
			{
				ch = getch();
			}
			//printf("%d\n", ch);
			gotoxy(c_x * 2, c_y);
			printf("  ");
			switch (ch)
			{
				//case UP:
				//c_y -= 1;
				//break;
				//case DOWN:
				//c_y += 1;
				//break;
			case LEFT:
				c_x -= 1;
				IsMove(&c_x);
				break;
			case RIGHT:
				c_x += 1;
				IsMove(&c_x);
				break;
			}
			gotoxy(c_x * 2, c_y);
			printf("☆");
		}


	}


	return 0;
}