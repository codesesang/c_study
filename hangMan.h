#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char str[5][20] =
{
	"red",
	"yellow",
	"green",
	"blue",
	"color"
};
char pStr[20] = ""; //�������� ���� �ܾ�
char sStr[20] = ""; //"*"
int life = 5; //���

void IniGame()

{
	int num = rand() % 5;
	int i = 0;

	strcpy(pStr, str[num]); //�߿��� �κ� str[num] 2���� �迭�� ������ ���� �ּ�

	int len = strlen(pStr);

	for (i = 0; i < len; i++)
	{
		sStr[i] = '*';
	}
	sStr[i] = '\0';
}

int CheckKey(char key)

{
	int len = strlen(pStr);
	int i = 0, j = 0, check = 0;
	char arr[5] = { 0, };

	for (i = 0; i < len; i++)
	{
		if (key == pStr[i])
		{
			sStr[i] = key;

			check = 1;
		}
	}

	return check;
}

void PrintfState()

{
	puts(""); // Ű���带 �Է�������?

	switch (life)
	{
	case 0:
		printf("�ۡۡۡۡ�\n");
		break;
	case 1:
		printf("�ܡۡۡۡ�\n");
		break;
	case 2:
		printf("�ܡܡۡۡ�\n");
		break;
	case 3:
		printf("�ܡܡܡۡ�\n");
		break;
	case 4:
		printf("�ܡܡܡܡ�\n");
		break;
	default:
		printf("�ܡܡܡܡ�\n");
		break;
	}


}

int CheckGameOver()

{
	if (0 == life)
	{
		return 1004;
	}

	int len = strlen(pStr);
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if ('*' == sStr[i])
		{
			return 4001;
		}
	}

	return 0;
}

int hangMan()
{
	char arr[5] = { 0, };
	char key;
	int i = 0, j;

	srand(time(NULL));
	IniGame();

	printf("%s\n", pStr);
	printf("%s\n", sStr);

	while (1)
	{
		printf("Word=%s\n", sStr);
		printf("Life=%d\n", life);

		key = getch();  // getch()�� _getch (�Է�o,���x) �� ���̰� ���?
		arr[i] = key;

		if (0 == CheckKey(key)) //�ܾ ������ 1, �ٸ��� 0 �̶� �ٸ��� �������� ���ҵȴ�.
		{
			for (j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					printf("\n�ߺ�\n");
					break;
				}
			}
			i++;

			life--;
		}

		PrintfState();

		if (0 == CheckGameOver())
		{
			printf("\nGame Clear\n");
			break;
		}
		else if (1004 == CheckGameOver())
		{
			printf("\nYou Lose\n");
			break;
		}
	}

	
	return 0;
}