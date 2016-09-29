#include <stdio.h>
#include <windows.h>
#include <string.h>

#define length 50
#define k_length 8

void Init();
void Encry();
void Decry();

int Playfair()
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

	printf(">>Playfair��ȣ ���α׷�<<\n");
	printf("��ȣȭ(0), ��ȣȭ(1), ������(2) : ");
	scanf("%d", &answer);

	system("cls");

	switch (answer)
	{
	case 0:
		Encry();
		break;
	case 1:
		Decry();
		break;
	case 2:
		exit(0);
		break;
	default:
		Playfair();
		break;
	}
}

void Encry()
{
	char M[length]; //��
	int E[length]; //��ȣȭ
	char C[length]; //��ȣ��
	char K[k_length] = { 0 }; //Ű��
	char K_arr[25] = { 0 }; //Ű�迭
	char Karr[5][5] = { 0 }; //2���� Ű�迭 
	int M_len;
	int K_len;
	int i;
	int j;
	char alpha[25] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int len = 0;
	int si = 0;

	printf(">>Playfair ��ȣȭ<<\n");
	printf("�� �Է�(�ҹ���) : ");
	scanf("%s", M);

	M_len = strlen(M);

	if (M_len % 2 == 1)
	{
		M[M_len] = 'x';
	}
	M[M_len + 1] = '\0';

	M_len = strlen(M);

	for (i = 0; i < M_len; i++)
	{
		if ('j' == M[i])
		{
			M[i] = 'i';
		}
	}

	printf("Ű�� �Է�(�빮�� and 7�� ����) : ");
	scanf("%s", K);

	K_len = strlen(K);

	for (i = 0; i < K_len; i++)
	{
		if ('J' == K[i])
		{
			K[i] = 'I';
		}
	}

	for (i = 0; i < K_len; i++)
	{
		for (j = 0; j < 25; j++)
		{
			if (K[i] == alpha[j])
			{
				K_arr[si] = alpha[j];

				alpha[j] = 0;

				si++;

				break;
			}
		}
	}

	for (i = 0;i < 25; i++)
	{
		if (0 != alpha[i])
		{
			K_arr[si] = alpha[i];

			alpha[i] = 0;

			si++;
		}
	}

	si = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			Karr[i][j] = K_arr[si];

			si++;
		}
	}

	printf(">>key table<<\n");

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%c  ", Karr[i][j]);
		}
		printf("\n");
	}

	for (si = 0; si < M_len; si+=2)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (M[si] - 97 == Karr[i][j] - 65)
				{
					for (int a = 0; a < 5; a++)
					{
						for (int b = 0; b < 5; b++)
						{
							if (M[si + 1] - 97 == Karr[a][b] - 65)
							{
								if (i == a)
								{
									E[si] = Karr[i][(j + 1) % 5] - 65;
									E[si + 1] = Karr[a][(b + 1) % 5] - 65;
								}

								else if (j == b)
								{
									E[si] = Karr[(i + 1) % 5][j] - 65;
									E[si + 1] = Karr[(a + 1) % 5][b] - 65;
								}

								else
								{
									E[si] = Karr[i][b] - 65;
									E[si + 1] = Karr[a][j] - 65;
								}
							}
						}
					}
				}
			}
		}
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

void Decry()
{
	char M[length]; //��
	int D[length]; //��ȣȭ
	char C[length]; //��ȣ��
	char K[k_length] = { 0 }; //Ű��
	char K_arr[25] = { 0 }; //Ű�迭
	char Karr[5][5] = { 0 }; //2���� Ű�迭 
	int C_len;
	int K_len;
	int i;
	int j;
	char alpha[25] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int len = 0;
	int si = 0;

	printf(">>Playfair ��ȣȭ<<\n");
	printf("��ȣ�� �Է�(�빮��) : ");
	scanf("%s", C);

	C_len = strlen(C);

	if (C_len % 2 == 1)
	{
		M[C_len] = 'X';
	}
	M[C_len + 1] = '\0';

	C_len = strlen(C);

	for (i = 0; i < C_len; i++)
	{
		if ('J' == M[i])
		{
			M[i] = 'I';
		}
	}

	printf("Ű�� �Է�(�빮�� and 7�� ����) : ");
	scanf("%s", K);

	K_len = strlen(K);

	for (i = 0; i < K_len; i++)
	{
		if ('J' == K[i])
		{
			K[i] = 'I';
		}
	}

	for (i = 0; i < K_len; i++)
	{
		for (j = 0; j < 25; j++)
		{
			if (K[i] == alpha[j])
			{
				K_arr[si] = alpha[j];

				alpha[j] = 0;

				si++;

				break;
			}
		}
	}

	for (i = 0; i < 25; i++)
	{
		if (0 != alpha[i])
		{
			K_arr[si] = alpha[i];

			alpha[i] = 0;

			si++;
		}
	}

	si = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			Karr[i][j] = K_arr[si];

			si++;
		}
	}

	printf(">>key table<<\n");

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%c  ", Karr[i][j]);
		}
		printf("\n");
	}

	for (si = 0; si < C_len; si += 2)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (C[si] - 65 == Karr[i][j] - 65)
				{
					for (int a = 0; a < 5; a++)
					{
						for (int b = 0; b < 5; b++)
						{
							if (C[si + 1] - 65 == Karr[a][b] - 65)
							{
								if (i == a)
								{
									D[si] = Karr[i][((j - 1) + 5) % 5] - 65;
									D[si + 1] = Karr[a][((b - 1) + 5) % 5] - 65;
								}

								else if (j == b)
								{
									D[si] = Karr[((i - 1) + 5) % 5][j] - 65;
									D[si + 1] = Karr[((a - 1) + 5) % 5][b] - 65;
								}

								else
								{
									D[si] = Karr[i][b] - 65;
									D[si + 1] = Karr[a][j] - 65;
								}
							}
						}
					}
				}
			}
		}
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
