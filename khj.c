#pragma warning(disable:4996)



/*
#include<stdio.h>
void main()
{
	char answer;    //프로그램의 실행과 종료를 선택 할 수 있는 문자 변수를 선언한다.

	do                //반복을 하기 위해 do~while문을 사용한다.
	{
		printf("=============================================================\n");
		printf("사칙연산이 가능한 프로그램입니다.\n");
		printf("프로그램을 실행하시겠습니까? (Y/N) : ");
		flushall();                          //오버플로우를 방지하기 위해 사용한다.
		scanf("%c", &answer);        //프로그램의 실행여부를 입력 받기 위해 사용한다.
		printf("-------------------------------------------------------------\n");

		if (answer == 'y' || answer == 'Y')   //프로그램을 실행 할 경우를 조건문if를 사용한다.
		{
			float su1, su2, su3;  //실수 값까지의 계산을 위해 실수값의 변수를 선언한다.
			char giho;       //연산을 하고 싶은 산술연산자 값의 변수를 선언한다.        

			printf("사칙연산을 할 첫번째 수를 입력해주세요. : ");
			scanf("%f", &su1);     //첫번째 값을 입력받는다.  
			printf("사칙연산을 할 기호를 입력해주세요.(+, -, *, /) : ");
			flushall();                 //오버플로우를 방지하기 위해 사용한다.
			scanf("%c", &giho);   //사칙연산 기호를 입력받는다.
			printf("사칙연산을 할 두번째 수를 입력해주세요. : ");
			scanf("%f", &su2);    //두번쨰 값을 입력받는다.
			printf("-------------------------------------------------------------\n");

			switch (giho)           //switch를 통해 입력받은 기호에 따라 연산을 실행한다.
			{
			case '+':              //덧셈의 경우
				su3 = su1 + su2; //덧셈 결과값의 계산식을 정의한다.
				printf("입력하신 연산의 답은 %.2f %c %.2f = %.2f 입니다.\n\n", su1, giho, su2, su3);  //덧셈의 결과값이 출력된다.
				break;      //덧셈이 아닌 경우 break를 통해 빠져나온다. 
			case '-':             //뺄셈의 경우
				su3 = su1 - su2;  //뺄셈 결과값의 계산식을 정의한다.
				printf("입력하신 연산의 답은 %.2f %c %.2f = %.2f 입니다.\n\n", su1, giho, su2, su3);  //뺄셈의 결과값이 출력된다.
				break;       //뺄셈이 아닌 경우 break를 통해 빠져나온다.
			case '*':             //곱셈의 경우
				su3 = su1*su2;  //곱셈 결과값의 계산식을 정의한다.
				printf("입력하신 연산의 답은 %.2f %c %.2f = %.2f 입니다.\n\n", su1, giho, su2, su3);  //곱셈의 결과값이 출력된다.
				break;     //곱셈이 아닌 경우 break를 통해 빠져나온다.
			case '/':            //나눗셈의 경우
				(float)su3 = (float)su1 / su2;  //덧셈 결과값의 계산식을 정의한다.
				printf("입력하신 연산의 답은 %.2f %c %.2f = %.2f 입니다.\n\n", su1, giho, su2, su3);  //나눗셈의 결과값이 출력된다.
				break;       //나눗셈이 아닌 경우 break를 통해 빠져나온다.
			default:              //사칙연산이 아닌 경우
				printf("연산가능한 기호가 아닙니다.\n다시입력해주세요.\n");  //사칙연산이 아닌경우가 출력된다.
				break;      //이 경우가 아닌 경우 break를 통해 빠져나온다.
			}
		}
		else if (answer == 'n' || answer == 'N')  //프로그램을 실행 하지 않을 경우 else if를 사용한다.
		{
			printf("-------------------------------------------------------------\n");
			printf("\t※※※프로그램이 종료되었습니다.※※※\n");
			printf("=============================================================\n");
			break;  //break를 통해 반복문에서 빠져나온다. 
		}
		else   //실행(Y,y), 종료(N,n)가 아닌 경우 else를 사용한다.
		{
			printf("-------------------------------------------------------------\n");
			printf("입력가능 문자는 실행(y, Y), 종료(n, N) 입니다.\n");
			printf("다시 입력해주세요.\n");
			printf("=============================================================\n");
		}
	} while (answer != 'n' || answer != 'N'); //실행여부를 종료(N,n)할 경우 반복문에서 빠져나온다.
}



#include<stdio.h>
void main()
{
	int a, b, c, d;

	for (a = 0; a < 11; a++)
	{
		if (a == 0 || a == 10)
		{
			for (b = 0; b < 11; b++)
			{
				printf("*");
			}
			printf("\n");
		}
		else
		{
			printf("*");
			for (c = 1; c < a; c++)
			{
				printf(" ");
			}
			printf("*");
			for (d = 1; d < 10 - a; d++)
			{
				printf(" ");
			}
			printf("*\n");
		}
	}
}




#include<stdio.h>
void main()
{
	char answer;
	
	do
	{
		printf("입력한 달의 마지막 날을 알려주는 프로그램입니다.\n");
		printf("실행하시겠습니까?(Y/N) : ");
		scanf("%c", &answer);

		if (answer == 'y' || answer == 'Y')
		{
			int mon;

			printf("마지막 날을 알고싶은 달을 입력하세요 : ");
			scanf("%d", &mon);

			switch (mon)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				printf("입력하신 달의 마지막 날은 31일 입니다.\n");
				break;
			case 2:
				printf("입력하신 달의 마지막 날은 28일 입니다.\n");
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				printf("입력하신 달의 마지막 날은 30일 입니다.\n");
				break;
			default:
				printf("입력가능한 문자가 아닙니다.");
				break;
			}
		}
		else if (answer == 'n' || answer == 'N')
		{
			printf("\t\t※※※프로그램이 종료되었습니다.※※※\n");
			break;
		}
		else
		{
			printf("입력가능 문자는 n, N, y, Y 입니다.\n");
			printf("다시 입력해주세요.\n");
		}
	} while (answer != 'n' || answer != 'N');
}



#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main()
{
	int lotto[3][7], i, j, input;/// 왜 문자열을 먼저 써야하나

	srand(time(NULL));

	while (1)
	{
		printf("로또 프로그램입니다.\n");
		printf("로또 몇 개를 사시겠습니까?\n");
		scanf("%d", &input);

		for (i = 0; i < input; i++)
		{
			for (j = 0; j < 7; j++)
			{
				lotto[i][j] = rand() % 46 + 1;
				printf("%d\t", lotto[i][j]);
			}
			printf("\n");
		}
	}
}


//Q.11
#include <stdio.h>
void main()
{
	int a, b, c;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5 - a; b++)
		{
			printf("* ");
		}
		for (c = 1; c < a; c++)
		{
			printf(" *");
		}
		printf("\n");
	}
}



//Q.10
#include <stdio.h>
void main()
{
	int a, b, c;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <a; b++)
		{
			printf("* ");
		}
		for (c = 1; c <= 5 - a; c++)
		{
			printf(" *");
		}
		printf("\n");
	}
}




//Q.9
#include <stdio.h>
void main()
{
	int a, b, c;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5 - a; b++)
		{
			printf(" ");
		}
		printf("*");
		for (c = 1; c < a; c++)
		{
			printf(" *");
		}
		printf("\n");
	}
}




//Q.8
#include <stdio.h>
void main()
{
	int a, b, c;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b < a; b++)
		{
			printf(" ");
		}
		printf("*");
		for (c = 1; c <= 5 - a; c++)
		{
			printf(" *");
		}
		printf("\n");
	}
}



//Q.7
#include <stdio.h>
void main()
{
	int a, b;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b < 6 - a; b++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}



//Q.6
#include <stdio.h>
void main()
{
	int a, b;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b < a; b++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}




//Q.5
#include <stdio.h>
void main()
{
	int a, b;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			printf("%d",b);
		}
		printf("\n");
	}
}





//Q.4
#include <stdio.h>
void main()
{
	int a, b;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++);
		{
			printf("%d%d%d%d%d",a,a,a,a,a);
		}
		printf("\n");
	}
}




//Q.3
#include <stdio.h>
void main()
{
	int a, b;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			printf("*");
		}
		printf("\n");
	}
}


//Q.2
#include <stdio.h>
void main()
{
	int a;
	for (a = 1; a <= 5; a++)
	{
		printf("*\n");
	}
}


//Q.1
#include <stdio.h>
void main()
{
	int a;
	
	for (a = 1; a <= 5; a++)
	{
		printf("*");
	}
	printf("\n");
}
*/