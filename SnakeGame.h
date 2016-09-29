
#pragma warning (disable:4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define up 72
#define down 80
#define left 75
#define right 77
#define START 5
#define DIRECTION 2

typedef struct _snake
{
	int x;
	int y;
}snake;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void border(int map[25][25])
{
	int i, j;

	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 25; j++)
		{
			if (0 == i || 0 == j || 24 == i || 24 == j)
				printf("°·");
			else
				printf("  ");
		}
		printf("\n");
	}
}

void initsnakelocation(snake* ps)
{
	int i;

	for (i = 0; i < START; i++)
	{
		ps[i].x = 20 + 2 * i;
		ps[i].y = 8;
		gotoxy(ps[i].x, ps[i].y);
		printf("¢∏");
	}
}

void fooddrop(snake* ps, snake* food, int length)
{
	int i;

	do
	{
		food->x = rand() % 23 * 2 + 2;
		food->y = rand() % 23 + 1;

		for (i = 0; i < length; i++)
		{
			if (food->x == ps[i].x && food->y == ps[i].y)
				break;

			if (i == length - 1)
			{
				gotoxy(food->x, food->y);
				gotoxy(food->x, food->y);
				printf("°‹");

				return;
			}
		}
	} while (1);
}

void showlength(int length)
{
	gotoxy(56, 10);
	printf("«ˆ¿Á πÏ ±Ê¿Ã");
	gotoxy(60, 12);
	printf("%d", length);
}

int iscrash(snake* ps, int length)
{
	int i;

	if (ps[0].x < 2 || ps[0].x > 47 || ps[0].y < 1 || ps[0].y > 23)
		return 1;

	for (i = 1; i < length; i++)
	{
		if (ps[0].x == ps[i].x && ps[0].y == ps[i].y)
			return 1;
	}

	return 0;
}

int main()
{
	int map[25][25] = { 0 };
	int direction = 2;
	int length = START;
	int speed = 150;
	int i;

	snake* ps = (snake*)malloc(sizeof(snake)*START);
	snake food;

	system("mode con:cols=75 lines=26");
	system("title snake game");

	border(map);
	initsnakelocation(ps);
	fooddrop(ps, &food, length);
	showlength(length);

	while (1)
	{
		char key;

		key = getch();

		switch (key)
		{
		case up:
			if (direction != 1)
				direction = 0;
			break;
		case down:
			if (direction != 0)
				direction = 1;
			break;
		case left:
			if (direction != 3)
				direction = 2;
			break;
		case right:
			if (direction != 2)
				direction = 3;
			break;
		}

		while (!kbhit())
		{
			if (!(ps[length - 1].x == ps[length - 2].x && ps[length - 1].y == ps[length - 2].y))
			{
				gotoxy(ps[length - 1].x, ps[length - 1].y);
				printf("  ");
			}

			for (i = length - 1; i > 0; i--)
				ps[i] = ps[i - 1];

			switch (direction)
			{
			case 0:
				ps[0].y -= 1;
				gotoxy(ps[0].x, ps[0].y);
				printf("°„");
				break;
			case 1:
				ps[0].y += 1;
				gotoxy(ps[0].x, ps[0].y);
				printf("°Â");
				break;
			case 2:
				ps[0].x -= 2;
				gotoxy(ps[0].x, ps[0].y);
				printf("¢∏");
				break;
			case 3:
				ps[0].x += 2;
				gotoxy(ps[0].x, ps[0].y);
				printf("¢∫");
				break;
			}

			if (food.x == ps[0].x && food.y == ps[0].y)
			{
				length++;

				ps = (snake *)realloc(ps, sizeof(snake) * length);

				ps[length - 1] = ps[length - 2];

				fooddrop(ps, &food, length);
				showlength(length);

				if (length % 5 == 0)
					speed -= 10;
			}
			Sleep(speed);

			if (1 == iscrash(ps, length))
				break;
		}
		if (1 == iscrash(ps, length))
			break;
	}

	system("cls");
	free(ps);

	return 0;
}
