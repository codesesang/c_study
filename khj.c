#pragma warning(disable:4996)



/*
#include<stdio.h>
void main()
{
	char answer;    //���α׷��� ����� ���Ḧ ���� �� �� �ִ� ���� ������ �����Ѵ�.

	do                //�ݺ��� �ϱ� ���� do~while���� ����Ѵ�.
	{
		printf("=============================================================\n");
		printf("��Ģ������ ������ ���α׷��Դϴ�.\n");
		printf("���α׷��� �����Ͻðڽ��ϱ�? (Y/N) : ");
		flushall();                          //�����÷ο츦 �����ϱ� ���� ����Ѵ�.
		scanf("%c", &answer);        //���α׷��� ���࿩�θ� �Է� �ޱ� ���� ����Ѵ�.
		printf("-------------------------------------------------------------\n");

		if (answer == 'y' || answer == 'Y')   //���α׷��� ���� �� ��츦 ���ǹ�if�� ����Ѵ�.
		{
			float su1, su2, su3;  //�Ǽ� �������� ����� ���� �Ǽ����� ������ �����Ѵ�.
			char giho;       //������ �ϰ� ���� ��������� ���� ������ �����Ѵ�.        

			printf("��Ģ������ �� ù��° ���� �Է����ּ���. : ");
			scanf("%f", &su1);     //ù��° ���� �Է¹޴´�.  
			printf("��Ģ������ �� ��ȣ�� �Է����ּ���.(+, -, *, /) : ");
			flushall();                 //�����÷ο츦 �����ϱ� ���� ����Ѵ�.
			scanf("%c", &giho);   //��Ģ���� ��ȣ�� �Է¹޴´�.
			printf("��Ģ������ �� �ι�° ���� �Է����ּ���. : ");
			scanf("%f", &su2);    //�ι��� ���� �Է¹޴´�.
			printf("-------------------------------------------------------------\n");

			switch (giho)           //switch�� ���� �Է¹��� ��ȣ�� ���� ������ �����Ѵ�.
			{
			case '+':              //������ ���
				su3 = su1 + su2; //���� ������� ������ �����Ѵ�.
				printf("�Է��Ͻ� ������ ���� %.2f %c %.2f = %.2f �Դϴ�.\n\n", su1, giho, su2, su3);  //������ ������� ��µȴ�.
				break;      //������ �ƴ� ��� break�� ���� �������´�. 
			case '-':             //������ ���
				su3 = su1 - su2;  //���� ������� ������ �����Ѵ�.
				printf("�Է��Ͻ� ������ ���� %.2f %c %.2f = %.2f �Դϴ�.\n\n", su1, giho, su2, su3);  //������ ������� ��µȴ�.
				break;       //������ �ƴ� ��� break�� ���� �������´�.
			case '*':             //������ ���
				su3 = su1*su2;  //���� ������� ������ �����Ѵ�.
				printf("�Է��Ͻ� ������ ���� %.2f %c %.2f = %.2f �Դϴ�.\n\n", su1, giho, su2, su3);  //������ ������� ��µȴ�.
				break;     //������ �ƴ� ��� break�� ���� �������´�.
			case '/':            //�������� ���
				(float)su3 = (float)su1 / su2;  //���� ������� ������ �����Ѵ�.
				printf("�Է��Ͻ� ������ ���� %.2f %c %.2f = %.2f �Դϴ�.\n\n", su1, giho, su2, su3);  //�������� ������� ��µȴ�.
				break;       //�������� �ƴ� ��� break�� ���� �������´�.
			default:              //��Ģ������ �ƴ� ���
				printf("���갡���� ��ȣ�� �ƴմϴ�.\n�ٽ��Է����ּ���.\n");  //��Ģ������ �ƴѰ�찡 ��µȴ�.
				break;      //�� ��찡 �ƴ� ��� break�� ���� �������´�.
			}
		}
		else if (answer == 'n' || answer == 'N')  //���α׷��� ���� ���� ���� ��� else if�� ����Ѵ�.
		{
			printf("-------------------------------------------------------------\n");
			printf("\t�ءء����α׷��� ����Ǿ����ϴ�.�ءء�\n");
			printf("=============================================================\n");
			break;  //break�� ���� �ݺ������� �������´�. 
		}
		else   //����(Y,y), ����(N,n)�� �ƴ� ��� else�� ����Ѵ�.
		{
			printf("-------------------------------------------------------------\n");
			printf("�Է°��� ���ڴ� ����(y, Y), ����(n, N) �Դϴ�.\n");
			printf("�ٽ� �Է����ּ���.\n");
			printf("=============================================================\n");
		}
	} while (answer != 'n' || answer != 'N'); //���࿩�θ� ����(N,n)�� ��� �ݺ������� �������´�.
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
		printf("�Է��� ���� ������ ���� �˷��ִ� ���α׷��Դϴ�.\n");
		printf("�����Ͻðڽ��ϱ�?(Y/N) : ");
		scanf("%c", &answer);

		if (answer == 'y' || answer == 'Y')
		{
			int mon;

			printf("������ ���� �˰���� ���� �Է��ϼ��� : ");
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
				printf("�Է��Ͻ� ���� ������ ���� 31�� �Դϴ�.\n");
				break;
			case 2:
				printf("�Է��Ͻ� ���� ������ ���� 28�� �Դϴ�.\n");
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				printf("�Է��Ͻ� ���� ������ ���� 30�� �Դϴ�.\n");
				break;
			default:
				printf("�Է°����� ���ڰ� �ƴմϴ�.");
				break;
			}
		}
		else if (answer == 'n' || answer == 'N')
		{
			printf("\t\t�ءء����α׷��� ����Ǿ����ϴ�.�ءء�\n");
			break;
		}
		else
		{
			printf("�Է°��� ���ڴ� n, N, y, Y �Դϴ�.\n");
			printf("�ٽ� �Է����ּ���.\n");
		}
	} while (answer != 'n' || answer != 'N');
}



#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main()
{
	int lotto[3][7], i, j, input;/// �� ���ڿ��� ���� ����ϳ�

	srand(time(NULL));

	while (1)
	{
		printf("�ζ� ���α׷��Դϴ�.\n");
		printf("�ζ� �� ���� ��ðڽ��ϱ�?\n");
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