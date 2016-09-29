#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void InitGame()
{
	printf("Baseball Game!!\n");
	srand(time(NULL));
}

void Computer(int com[3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		com[i] = rand() % 9;
		for (j = 0; j < i; j++)
		{
			if (com[i] == com[j])
			{
				i--;
			}
		}
	}
}

void Person(int per[3])
{
	int i;

	printf("서로 다른 세 수를 입력 : ");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &per[i]);
	}
}

void IsCompare(int com[3], int per[3], int* ss, int* bb)
{
	int i;
	int j;
	int s = 0;
	int b = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (com[i] == per[j])
			{
				if (i == j)
				{
					s++;
				}
				else
				{
					b++;
				}
			}
		}
	}

	*ss = s;
	*bb = b;
}

int Regame()
{
	int answer;

	printf("Regame(-1) ?");
	scanf("%d", &answer);
	
	if (-1 == answer)
	{
		return -1;
	}

	return 0;
}

void BaseballGame()
{
	int com[3];
	int per[3];
	int i, j;
	int ss, bb;

	InitGame();

	while (1)
	{
		Computer(com);

		for (i = 0; i < 10; i++)
		{
			Person(per);
			IsCompare(com, per, &ss, &bb);

			printf("S : %d   B : %d\n", ss, bb);
			
			if (3 == ss)
			{
				printf("You WIN !!!\n");
				break;
			}
			if (9 == i)
			{
				printf("You LOSE !!!\n");
				for (j = 0; j < 3; j++)
				{
					printf("%d ", com[j]);
				}
				printf("\n");
				break;
			}
		}
		if (0 == Regame())
		{
			break;
		}
	}
}