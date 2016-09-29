#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct _SUDOKU{
	int	garo;
	int sero;
	int index;
	int area;
}SUDOKU;

SUDOKU  su[9][9];

void Check()
{
	int i, j;
	int k = -1;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			su[i][j].garo = i;
			su[i][j].sero = j;
			su[i][j].index = 0;
		}
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
				k++;
			su[i][j].area = k;
		}
		if (i % 3 != 2)
			k -= 3;
	}
}

void InsertSudoku()
{
	int i, j, k;

	srand(time(NULL));

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			su[i][j].index = rand() % 9 + 1;

			
		}
	}
}

void Sudoku()
{
	int lotto[9] = { 0, };
	int i, j;

	Check();
	InsertSudoku();

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d  ", su[i][j].index);
			if (j % 3 == 2)
				printf("  ");
		}
		if (i % 3 == 2)
			printf("\n");
		printf("\n");
	}
}
