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
	
	printf(">>Vigenere��ȣ ���α׷�<<\n");
	printf("��ȣȭ(0), ��ȣȭ(1), ������(2) : ");
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
	char M[LENGTH]; //��
	int E[LENGTH]; //��ȣȭ
	char C[LENGTH]; //��ȣ��
	char K[K_LENGTH]; //Ű��
	int M_len;
	int K_len;
	int i;

	printf(">>Vigenere ��ȣȭ<<\n");
	printf("�� �Է�(�ҹ���) : ");
	scanf("%s", M);

	M_len = strlen(M);

	printf("Ű�� �Է�(�빮�� and 7�� ����) : ");
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

	printf("��ȣ�� ���(�빮��) : ");

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
	char M[LENGTH]; //��
	int D[LENGTH]; //��ȣȭ
	char C[LENGTH]; //��ȣ��
	char K[K_LENGTH]; //Ű��
	int C_len;
	int K_len;
	int i;

	printf(">>Vigenere ��ȣȭ<<\n");
	printf("��ȣ�� �Է�(�빮��) : ");
	scanf("%s", C);

	C_len = strlen(C);

	printf("Ű�� �Է�(�빮�� and 7�� ����) : ");
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

	printf("�� ���(�ҹ���) : ");

	for (i = 0; i < C_len; i++)
	{
		M[i] = D[i] + 97;

		printf("%c", M[i]);
	}

	printf("\n");

	system("pause");
	system("cls");
}
