#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include <Windows.h>

#define MAX 100
#define ADD 1
#define DEL 2
#define MOD 3
#define SEARCH 4
#define ALL 5
#define EXIT 6

typedef struct A
{
	char num[20];
	char name[20];
	int check;
	// check �� : -1 ������ , 1 ������, 0 ������ ��
}a;

a ph[100];

void init() //check�� ��ȭ��ȣ�� ���ٴ� ǥ�ø� �Ѵ�
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		ph[i].check = -1;
	}
}

// ��ȭ��ȣ �߰�
void addPh()
{
	int i;

	// temp
	char addName[100] = "";
	char addNum[100] = "";

	printf("�� ��ȭ��ȣ �߰� ��\n");

	// �̸� �߰�
	printf("�߰��� �̸� : ");

	for (i = 0; i < MAX; i++)
	{
		if (ph[i].check != 1) // ��ȭ��ȣ�� ���� ������
		{
			scanf("%s", ph[i].name);
			strcpy(addName, ph[i].name);

			break;
		}
		else // ��ȭ��ȣ�� ������
		{

		}
	}
	// ��ȣ �߰�
	printf("�߰��� ��ȣ : ");

	for (i = 0; i < MAX; i++)
	{


		if (ph[i].check != 1) // ��ȭ��ȣ�� ���� ������
		{

			scanf("%s", ph[i].num);
			strcpy(addNum, ph[i].num);
			ph[i].check = 1;
			printf("[%.3d] �̸� : %s , ��ȣ : %s �� �߰��Ǿ����ϴ�.\n", i + 1, addName, addNum);

			break;
		}
		else // ��ȭ��ȣ�� ������
		{

		}
	}
}

// ��ȭ��ȣ ����
void delPh()
{
	char delName[100] = "";
	char delNum[100] = "";
	int i;

	printf("�� ��ȭ��ȣ ���� ��\n");

	printf("������ ��ȣ : ");
	scanf("%s", delNum);

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(ph[i].num, delNum) == 0)
		{
			printf("[ %.3d ] �̸� : %s, ��ȣ : %s�� �����Ǿ����ϴ�\n", i + 1, ph[i].name, ph[i].num);

			ph[i].check = 0;
			break;
		}
	}

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(ph[i].num, delNum) != 0)
		{
			printf("��ȣ����\n");
			break;
		}
	}
}

// ��ȭ��ȣ �˻�
void searchPh()
{
	char searchName[100] = "";
	char searchNum[100] = "";
	int i;

	printf("�� ��ȭ��ȣ �˻� ��\n");

	printf("�˻��� ��ȣ : ");
	scanf("%s", searchNum);

	for (i = 0; i < MAX; i++)
	{

		if (strcmp(ph[i].num, searchNum) == 0)
		{
			printf("[ %.3d ] �̸� : %s, ��ȣ : %s�� �˻��Ǿ����ϴ�\n", i + 1, ph[i].name, ph[i].num);
			break;
		}
	}

	for (i = 0; i < MAX; i++)
	{

		if (strcmp(ph[i].num, searchNum) != 0)
		{
			printf("��ȣ����\n");
			break;
		}
	}
}


// ��ȭ��ȣ ����
void moPh()
{
	char moName[100] = "";
	char moNum[100] = "";
	int i;

	printf("������ ��ȣ�Է� : ");
	scanf("%s", moNum);

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(moNum, ph[i].num) == 0)
		{
			printf("[ %.3d ] �̸� : %s   ��ȣ : %s\n", i + 1, ph[i].name, ph[i].num);
			printf("������ ��ȣ�Է� : ");
			scanf("%s", ph[i].num);
			printf("[ %.3d ] �̸� : %s, ��ȣ : %s�� �����Ǿ����ϴ�.\n", i + 1, ph[i].name, ph[i].num);
			break;
		}
	}
}

// ��ȭ��ȣ ��ü �����ֱ�
void allPh()
{
	int i;
	char input;

	printf("�� ����� ��ȭ��ȣ ��\n");

	for (i = 0; i < MAX; i++)
	{
		if (ph[i].check == -1) //��ȭ��ȣ �Է� ���Ѱ�
		{
			break;
		}
		else if (ph[i].check == 1) //��ȭ��ȣ �Է� �Ѱ�
		{
			printf("[ %.3d ] �̸� : %s   ��ȣ : %s\n", i + 1, ph[i].name, ph[i].num);
		}
		else  //������ ��
		{

		}
	}

}

// �޴�
void Mymenu()
{
	int choise;

	printf("1. ��ȭ��ȣ �߰�\n");
	printf("2. ��ȭ��ȣ ����\n");
	printf("3. ��ȭ��ȣ ����\n");
	printf("4. ��ȭ��ȣ �˻�\n");
	printf("5. ��ȭ��ȣ ��ü����\n");
	printf("6. ������\n");

	printf("���� : ");
	scanf("%d", &choise);

	system("cls");

	switch (choise)
	{
	case ADD:
		addPh();
		break;
	case DEL:
		delPh();
		break;
	case MOD:
		moPh();
		break;
	case SEARCH:
		searchPh();
		break;
	case ALL:
		allPh();
		break;
	case EXIT:
		exit(0);
		break;
	}

	system("pause"); //�ƹ�Ű�� ������ ����
	system("cls");   //ȭ�������
}

// ����
void startPh()
{
	printf("��ȭ��ȣ ���α׷��Դϴ�.\n");

	printf("�޴��� �����ϼ���.\n");

	Mymenu();
}