//#include <stdio.h>
//#include <windows.h>
//#include <string.h>
//#include "Sort.h"
//
//#define LENGTH 50
//#define K_LENGTH 10
//
//void Init();
//void Encry();
//void Decry();
//
//int Nihilist()
//{
//
//	while (1)
//	{
//		Init();
//	}
//
//	return 0;
//}
//
//void Init()
//{
//	int answer;
//
//	printf(">>Nihilist��ȣ ���α׷�<<\n");
//	printf("��ȣȭ(0), ��ȣȭ(1), ������(2) : ");
//	scanf("%d", &answer);
//
//	system("cls");
//
//	switch (answer)
//	{
//	case 0:
//		Encry();
//		break;
//	case 1:
//		Decry();
//		break;
//	case 2:
//		exit(0);
//		break;
//	default:
//		Nihilist();
//		break;
//	}
//}
//
//void Encry()
//{
//	char M[LENGTH]; //��
//	int E[LENGTH]; //��ȣȭ
//	char C[LENGTH]; //��ȣ��
//	char K[K_LENGTH]; //Ű��
//	char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//	int intK[K_LENGTH];
//	char NewK[K_LENGTH];
//	int M_len;
//	int K_len;
//	int len;
//	int i;
//	int j;
//	int k = 0;
//
//	printf(">>Nihilist ��ȣȭ<<\n");
//	printf("�� �Է�(�ҹ���) : ");
//	scanf("%s", M);
//
//	printf("Ű�� �Է�(�빮��, 7����) : ");
//	scanf("%s", &K);
//
//	K_len = strlen(K);
//
//	for (i = 0; i < 26; i++)
//	{
//		for (j = 0; j < K_len; j++)
//		{
//			if (alpha[i] == K[j])
//			{
//				NewK[j] = alpha[i];
//				intK[j] = k;
//				alpha[i] = '0';
//				k++;
//
//				break;
//			}
//		}
//	}
//	NewK[k] = '\0';
//	
//	K_len = strlen(NewK);
//
//	M_len = strlen(M);
//
//	k = 0;
//
//	while (K_len*K_len != M_len)
//	{
//		len = M_len;
//
//		M[len] = 97 + k;
//		M[len + 1] = '\0';
//		k++;
//
//		M_len = strlen(M);
//	}
//
//	M_len = strlen(M);
//
//	j = 0;
//
//	//printf("�� ���� ����� : %s\n", M);
//
//	for (i = 0; i < M_len; i++)
//	{
//		if (0 < i && i%K_len == 0)
//		{
//			j += K_len;
//		}
//		E[intK[i%K_len] + j] = M[i];
//	}
//
//	printf("\n>>�߰� ��ȣ��<<\n");
//
//	printf("    ");
//
//	for (i = 0; i < K_len; i++)
//	{
//		printf("%c ", NewK[i]);
//	}
//	printf("\n");
//	
//	printf("    ");
//
//	for (i = 0; i < K_len; i++)
//	{
//		printf("%d ", intK[i]);
//	}
//	
//	j = 0;
//
//	for (i = 0; i < M_len; i++)
//	{
//		if (i%K_len == 0)
//		{
//			printf("\n");
//			printf("%c ", NewK[j]);
//			printf("%d ", intK[j]);
//			j++;
//		}
//
//		printf("%c ", E[i]);
//	}
//
//	for (i = 0; i < M_len; i++)
//	{
//		if (i%K_len == 0)
//			j = 0;
//		C[(intK[i / K_len] * K_len) + j] = E[i];
//		j++;
//	}
//
//	printf("\n\n");
//
//	printf("��ȣ�� ���(�빮��) : ");
//
//	for (i = 0; i < M_len; i++)
//	{
//		C[i] -= 32;
//		printf("%c", C[i]);
//	}
//
//	printf("\n\n");
//
//	system("pause");
//	system("cls");
//}
//
//void Decry()
//{
//	char M[LENGTH]; //��
//	int D[LENGTH]; //��ȣȭ
//	char C[LENGTH]; //��ȣ��
//	char K[K_LENGTH]; //Ű��
//	char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//	int intK[K_LENGTH];
//	char NewK[K_LENGTH];
//	int C_len;
//	int K_len;
//	int len;
//	int i;
//	int j;
//	int k = 0;
//
//	printf(">>Nihilist ��ȣȭ<<\n");
//	printf("��ȣ�� �Է�(�빮��) : ");
//	scanf("%s", C);
//
//	printf("Ű�� �Է�(�빮��, 7����) : ");
//	scanf("%s", &K);
//
//	K_len = strlen(K);
//
//	for (i = 0; i < 26; i++)
//	{
//		for (j = 0; j < K_len; j++)
//		{
//			if (alpha[i] == K[j])
//			{
//				NewK[j] = alpha[i];
//				intK[j] = k;
//				alpha[i] = '0';
//				k++;
//
//				break;
//			}
//		}
//	}
//	NewK[k] = '\0';
//
//	K_len = strlen(NewK);
//
//	C_len = strlen(C);
//
//	j = 0;
//
//	for (i = 0; i < C_len; i++)
//	{
//		if (0 < i && i%K_len == 0)
//		{
//			j = 0;
//		}
//		D[i] = C[intK[i / K_len] * K_len + j] + 32;
//		j++;
//	}
//
//	printf("\n>>�߰� ��ȣ��<<\n");
//
//	printf("    ");
//
//	for (i = 0; i < K_len; i++)
//	{
//		printf("%c ", NewK[i]);
//	}
//	printf("\n");
//
//	printf("    ");
//
//	for (i = 0; i < K_len; i++)
//	{
//		printf("%d ", intK[i]);
//	}
//
//	j = 0;
//
//	for (i = 0; i < C_len; i++)
//	{
//		if (i%K_len == 0)
//		{
//			printf("\n");
//			printf("%c ", NewK[j]);
//			printf("%d ", intK[j]);
//			j++;
//		}
//
//		printf("%c ", D[i]);
//	}
//
//	j = 0;
//
//	for (i = 0; i < C_len; i++)
//	{
//		if (0 < i && i%K_len == 0)
//		{
//			j += K_len;
//		}
//		M[i] = D[intK[i%K_len] + j];
//	}
//	
//	printf("\n\n");
//
//	printf("�� ���(�ҹ���) : ");
//
//	for (i = 0; i < C_len; i++)
//	{
//		printf("%c", M[i]);
//	}
//
//	printf("\n\n");
//
//	system("pause");
//	system("cls");
//}