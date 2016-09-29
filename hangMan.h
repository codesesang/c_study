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
char pStr[20] = ""; //랜덤으로 뽑힌 단어
char sStr[20] = ""; //"*"
int life = 5; //목숨

void IniGame()

{
	int num = rand() % 5;
	int i = 0;

	strcpy(pStr, str[num]); //중요한 부분 str[num] 2차원 배열의 한줄의 시작 주소

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
	puts(""); // 키보드를 입력했을때?

	switch (life)
	{
	case 0:
		printf("○○○○○\n");
		break;
	case 1:
		printf("●○○○○\n");
		break;
	case 2:
		printf("●●○○○\n");
		break;
	case 3:
		printf("●●●○○\n");
		break;
	case 4:
		printf("●●●●○\n");
		break;
	default:
		printf("●●●●●\n");
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

		key = getch();  // getch()와 _getch (입력o,출력x) 의 차이가 모야?
		arr[i] = key;

		if (0 == CheckKey(key)) //단어가 같으면 1, 다르면 0 이라서 다르면 라이프가 감소된다.
		{
			for (j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					printf("\n중복\n");
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