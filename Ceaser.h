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
	
	printf(">>Ceaser��ȣ ���α׷�<<\n");
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
		Ceaser();
		break;
	}
}

void encry()
{
	char M[LENGTH]; //��
	int E[LENGTH]; //��ȣȭ
	char C[LENGTH]; //��ȣ��
	int len;
	int K; //Ű��
	int i;
	int j;


	printf(">>Ceaser ��ȣȭ<<\n");
	printf("�� �Է�(�ҹ���) : ");
	scanf("%s", M);

	printf("Ű�� �Է�(1~25) : ");
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

	printf("��ȣ�� ���(�빮��) : ");

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
	char M[LENGTH]; //��
	int D[LENGTH]; //��ȣȭ
	char C[LENGTH]; //��ȣ��
	int len;
	int K; //Ű��
	int i;
	int j;

	printf(">>Ceaser ��ȣȭ<<\n");
	printf("��ȣ�� �Է�(�빮��) : ");
	scanf("%s", C);

	printf("Ű�� �Է�(1~25) : ");
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

	printf("�� ���(�ҹ���) : ");

	for (i = 0; i < len; i++)
	{
		M[i] = D[i] + 97;

		printf("%c", M[i]);
	}

	printf("\n");

	system("pause");
	system("cls");
}
