#pragma warning(disable:4996)
#include <stdio.h>

int first()
{
	int input;
	int i, j;

	printf("구구단 프로그램\n");
	printf("단수 입력 : ");
	scanf("%d", &input);
	for (i = 0; i < 9; i++)
	{
		printf("%d * %d = ", input, i + 1);
		for (j = 0; j < input*(i + 1); j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

int sec()
{
	char input[20];
	int i;

	printf("대소문자를 바꿔주는 프로그램\n");
	printf("문자 입력 : ");
	scanf("%s", input);

	for (i = 0; i < 20; i++)
	{
		if (input[i] >= 65 && input[i] <= 90)
		{
			input[i] += 32;
		}
		else if (input[i] >= 97 && input[i] <= 122)
		{
			input[i] -= 32;
		}
	}
	printf("변환된 문자 : %s", input);

	return 0;
}

int three()
{
	char input[80];
	int i, cha = 0;

	printf("쌍괄호인지 확인하는 프로그램\n");
	printf("괄호 입력 : ");
	scanf("%s", input);

	for (i = 0; i < 80; i++)
	{
		if (input[i] == '(')
		{
			cha += 1;
		}
		else if (input[i] == ')')
		{
			cha -= 1;
		}
		if (cha < 0)
		{
			printf("NO");
			break;
		}
	}

	if (cha == 0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

	return 0;
}

int four()
{
	int input[5];
	int i, j;

	printf("최소값 최대값을 구하는 프로그램\n");
	printf("정수 5개 입력 : ");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &input[i]);
	}
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			if (input[i] < input[j])
			{
				input[i] = 0;
				break;
			}
			else
			{
				input[j] = 0;
			}
		}
	}
	for (i = 0; i < 5; i++)

	{
		if (input[i] != 0)
		{
			printf("최대값 : %d\n", input[i]);
			break;
		}
	}

	return 0;
}

int five()
{
	int input[5][5] = { 0, };
	int i = 0, j = -1, su = 1;
	int a, b;
	int t = 1;
	
	for (b = 0; b < 5; b++)
	{
		for (a = 0; a < 5 - b; a++)
		{
			j += t;
			input[i][j] += su++;
		}
		for (a = 0; a < 4 - b; a++)
		{
			i += t;
			input[i][j] += su++;
		}
		t *= -1;
	}
		
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d\t", input[i][j]);
		}
		printf("\n");
	}

	return 0;
}