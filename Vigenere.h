#include <stdio.h>
#include <windows.h>
#include <string.h>

#define LENGTH 50
#define K_LENGTH 7

void Init();
void encry();
void decry();

int Vigenere()
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
	
	printf(">>Vigenere암호 프로그램<<\n");
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
		Vigenere();
		break;
	}
}

void encry()
{
	char M[LENGTH]; //평문
	int E[LENGTH]; //암호화
	char C[LENGTH]; //암호문
	char K[K_LENGTH]; //키값
	int M_len;
	int K_len;
	int i;

	printf(">>Vigenere 암호화<<\n");
	printf("평문 입력(소문자) : ");
	scanf("%s", M);

	M_len = strlen(M);

	printf("키값 입력(대문자 and 7자 이하) : ");
	scanf("%s", K);

	K_len = strlen(K);

	for (i = 0; i < M_len; i++)
	{
		E[i] = (M[i] - 97) + (K[i%K_len] - 65);

		if (E[i]>26)
			E[i] -= 26;

		else if (E[i] < 0)
			E[i] += 26;

	}

	printf("암호문 출력(대문자) : ");

	for (i = 0; i < M_len; i++)
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
	char K[K_LENGTH]; //키값
	int C_len;
	int K_len;
	int i;

	printf(">>Vigenere 복호화<<\n");
	printf("암호문 입력(대문자) : ");
	scanf("%s", C);

	C_len = strlen(C);

	printf("키값 입력(대문자 and 7자 이하) : ");
	scanf("%s", K);

	K_len = strlen(K);

	for (i = 0; i < C_len; i++)
	{
		D[i] = (C[i] - 65) - (K[i%K_len] - 65);

		if (D[i]>26)
			D[i] -= 26;

		else if (D[i] < 0)
			D[i] += 26;

	}

	printf("평문 출력(소문자) : ");

	for (i = 0; i < C_len; i++)
	{
		M[i] = D[i] + 97;

		printf("%c", M[i]);
	}

	printf("\n");

	system("pause");
	system("cls");
}
