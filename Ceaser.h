#include <stdio.h>
#include <windows.h>
#include <string.h>

#define LENGTH 50

void Init();
void encry();
void decry();

int Ceaser()
{

	while (1)
	{
		Init();
	}

	return 0;
}

void Init()
{
	int answer;
	
	printf(">>Ceaser암호 프로그램<<\n");
	printf("암호화(0), 복호화(1), 나가기(2) : ");
	scanf("%d", &answer);

	system("cls");

	switch (answer)
	{
	case 0:
		encry();
		break;
	case 1:
		decry();
		break;
	case 2:
		exit(0);
		break;
	default:
		Ceaser();
		break;
	}
}

void encry()
{
	char M[LENGTH]; //평문
	int E[LENGTH]; //암호화
	char C[LENGTH]; //암호문
	int len;
	int K; //키값
	int i;
	int j;


	printf(">>Ceaser 암호화<<\n");
	printf("평문 입력(소문자) : ");
	scanf("%s", M);

	printf("키값 입력(1~25) : ");
	scanf("%d", &K);

	len = strlen(M);

	for (i = 0; i < len; i++)
	{
		E[i] = (M[i] - 97) + K;

		if (E[i]>26)
			E[i] -= 26;

		else if (E[i] < 0)
			E[i] += 26;
	}

	printf("암호문 출력(대문자) : ");

	for (i = 0; i < len; i++)
	{
		C[i] = E[i] + 65;

		printf("%c", C[i]);
	}

	printf("\n");

	system("pause");
	system("cls");
}

void decry()
{
	char M[LENGTH]; //평문
	int D[LENGTH]; //복호화
	char C[LENGTH]; //암호문
	int len;
	int K; //키값
	int i;
	int j;

	printf(">>Ceaser 복호화<<\n");
	printf("암호문 입력(대문자) : ");
	scanf("%s", C);

	printf("키값 입력(1~25) : ");
	scanf("%d", &K);

	len = strlen(C);

	for (i = 0; i < len; i++)
	{
		D[i] = (C[i] - 65) - K;

		if (D[i]>26)
			D[i] -= 26;

		else if (D[i] < 0)
			D[i] += 26;
	}

	printf("평문 출력(소문자) : ");

	for (i = 0; i < len; i++)
	{
		M[i] = D[i] + 97;

		printf("%c", M[i]);
	}

	printf("\n");

	system("pause");
	system("cls");
}
