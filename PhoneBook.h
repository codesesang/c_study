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
	// check 값 : -1 없으면 , 1 있으면, 0 삭제한 값
}a;

a ph[100];

void init() //check에 전화번호가 없다는 표시를 한다
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		ph[i].check = -1;
	}
}

// 전화번호 추가
void addPh()
{
	int i;

	// temp
	char addName[100] = "";
	char addNum[100] = "";

	printf("▶ 전화번호 추가 ◀\n");

	// 이름 추가
	printf("추가할 이름 : ");

	for (i = 0; i < MAX; i++)
	{
		if (ph[i].check != 1) // 전화번호가 있지 않으면
		{
			scanf("%s", ph[i].name);
			strcpy(addName, ph[i].name);

			break;
		}
		else // 전화번호가 있으면
		{

		}
	}
	// 번호 추가
	printf("추가할 번호 : ");

	for (i = 0; i < MAX; i++)
	{


		if (ph[i].check != 1) // 전화번호가 있지 않으면
		{

			scanf("%s", ph[i].num);
			strcpy(addNum, ph[i].num);
			ph[i].check = 1;
			printf("[%.3d] 이름 : %s , 번호 : %s 가 추가되었습니다.\n", i + 1, addName, addNum);

			break;
		}
		else // 전화번호가 있으면
		{

		}
	}
}

// 전화번호 삭제
void delPh()
{
	char delName[100] = "";
	char delNum[100] = "";
	int i;

	printf("▶ 전화번호 삭제 ◀\n");

	printf("삭제할 번호 : ");
	scanf("%s", delNum);

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(ph[i].num, delNum) == 0)
		{
			printf("[ %.3d ] 이름 : %s, 번호 : %s가 삭제되었습니다\n", i + 1, ph[i].name, ph[i].num);

			ph[i].check = 0;
			break;
		}
	}

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(ph[i].num, delNum) != 0)
		{
			printf("번호없음\n");
			break;
		}
	}
}

// 전화번호 검색
void searchPh()
{
	char searchName[100] = "";
	char searchNum[100] = "";
	int i;

	printf("▶ 전화번호 검색 ◀\n");

	printf("검색할 번호 : ");
	scanf("%s", searchNum);

	for (i = 0; i < MAX; i++)
	{

		if (strcmp(ph[i].num, searchNum) == 0)
		{
			printf("[ %.3d ] 이름 : %s, 번호 : %s가 검색되었습니다\n", i + 1, ph[i].name, ph[i].num);
			break;
		}
	}

	for (i = 0; i < MAX; i++)
	{

		if (strcmp(ph[i].num, searchNum) != 0)
		{
			printf("번호없음\n");
			break;
		}
	}
}


// 전화번호 수정
void moPh()
{
	char moName[100] = "";
	char moNum[100] = "";
	int i;

	printf("수정할 번호입력 : ");
	scanf("%s", moNum);

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(moNum, ph[i].num) == 0)
		{
			printf("[ %.3d ] 이름 : %s   번호 : %s\n", i + 1, ph[i].name, ph[i].num);
			printf("수정될 번호입력 : ");
			scanf("%s", ph[i].num);
			printf("[ %.3d ] 이름 : %s, 번호 : %s가 수정되었습니다.\n", i + 1, ph[i].name, ph[i].num);
			break;
		}
	}
}

// 전화번호 전체 보여주기
void allPh()
{
	int i;
	char input;

	printf("▶ 저장된 전화번호 ◀\n");

	for (i = 0; i < MAX; i++)
	{
		if (ph[i].check == -1) //전화번호 입력 안한값
		{
			break;
		}
		else if (ph[i].check == 1) //전화번호 입력 한값
		{
			printf("[ %.3d ] 이름 : %s   번호 : %s\n", i + 1, ph[i].name, ph[i].num);
		}
		else  //삭제된 값
		{

		}
	}

}

// 메뉴
void Mymenu()
{
	int choise;

	printf("1. 전화번호 추가\n");
	printf("2. 전화번호 삭제\n");
	printf("3. 전화번호 수정\n");
	printf("4. 전화번호 검색\n");
	printf("5. 전화번호 전체보기\n");
	printf("6. 나가기\n");

	printf("선택 : ");
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

	system("pause"); //아무키나 누르면 종료
	system("cls");   //화면지우기
}

// 시작
void startPh()
{
	printf("전화번호 프로그램입니다.\n");

	printf("메뉴를 선택하세요.\n");

	Mymenu();
}