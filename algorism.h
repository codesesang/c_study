#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_SIZE 5

int g_lotto[LOTTO_SIZE];

void lotto()
{
	int i, j;

	srand(time(NULL));

	for (i = 0; i < LOTTO_SIZE; i++)
	{
		g_lotto[i] = rand() % LOTTO_SIZE + 1;
		for (j = 0; j < i; j++)
		{
			if (g_lotto[i] == g_lotto[j])
			{
				i--;
			}
		}
	}

	printf("정렬 전 : ");
	for (i = 0; i < LOTTO_SIZE; i++)
	{
		printf("%d  ", g_lotto[i]);
	}
	printf("\n");
}

void bubble()
{
	int i, j;
	int temp;

	printf("버블");

	lotto();

	for (i = 0; i < LOTTO_SIZE; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (g_lotto[i] < g_lotto[j])
			{
				temp = g_lotto[i];
				g_lotto[i] = g_lotto[j];
				g_lotto[j] = temp;
			}
		}
	}

	printf("버블정렬 후 : ");
	for (i = 0; i < LOTTO_SIZE; i++)
	{
		printf("%d  ", g_lotto[i]);
	}
	printf("\n");
}

void choice()
{
	int i, j;
	int min;
	int temp;

	printf("선택");

	lotto();

	for (j = 0; j < LOTTO_SIZE; j++)
	{
		min = g_lotto[j];

		for (i = j + 1; i < LOTTO_SIZE; i++)
		{

			if (g_lotto[i] > min)
			{
				min;
			}
			else
			{
				min = g_lotto[i];
				temp = g_lotto[i];
				g_lotto[i] = g_lotto[j];
				g_lotto[j] = temp;
			}
		}
	}
	

	printf("선택정렬 후 : ");
	for (i = 0; i < LOTTO_SIZE; i++)
	{
		printf("%d  ", g_lotto[i]);
	}
	printf("\n");
}

void insert()
{
	int i, j;
	int temp;

	printf("삽입");

	lotto();

	for (i = 0; i < LOTTO_SIZE - 1; i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			if (g_lotto[j] < g_lotto[j - 1])
			{
				temp = g_lotto[j];
				g_lotto[j] = g_lotto[j - 1];
				g_lotto[j - 1] = temp;
			}
			else
			{
				if (i > 0)
					break;
			}
		}
	}

	printf("삽입정렬 후 : ");
	for (i = 0; i < LOTTO_SIZE; i++)
	{
		printf("%d  ", g_lotto[i]);
	}
	printf("\n");
}