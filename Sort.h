#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 7

void Lotto(int lotto[]);
void PrintLotto(int lotto[]);
void QuickSort(int lotto[], int left, int right);

int Sort()
{
	int lotto[LENGTH];
	
	Lotto(lotto);

	printf("Sort Àü : ");

	PrintLotto(lotto);

	QuickSort(lotto, 0, LENGTH - 1);

	printf("Sort ÈÄ : ");

	PrintLotto(lotto);

	return 0;
}

void Lotto(int lotto[])
{
	int i;
	int j;

	srand(time(NULL));

	for (i = 0; i < LENGTH; i++)
	{
		lotto[i] = rand() % 45 + 1;

		for (j = 0; j < i; j++)
		{
			if (lotto[i] == lotto[j])
			{
				i--;

				break;
			}
		}
	}
}

void PrintLotto(int lotto[])
{
	int i;
	
	for (i = 0; i < LENGTH; i++)
	{
		printf("%2d  ", lotto[i]);
	}

	printf("\n");
}

void QuickSort(int lotto[],int left,int right)
{
	int pivot;
	int temp;
	int _left;
	int _right;
	
	pivot = lotto[left];
	_left = left;
	_right = right;

	while (right > left)
	{
		while (pivot < lotto[right])
		{
			right--;
		}

		if (right == left)
			break;

		while (pivot > lotto[left])
		{
			left++;
		}
		
		if (right == left)
		{
			temp = pivot;
			pivot = lotto[right];
			lotto[right] = temp;

			break;
		}

		if (lotto[left] > lotto[right])
		{
			temp = lotto[left];
			lotto[left] = lotto[right];
			lotto[right] = temp;
		}
	}

	lotto[left] = pivot;
	pivot = left;
	left = _left;
	right = _right;

	if (pivot > left)
		QuickSort(lotto, left, pivot - 1);

	if (pivot < right)
		QuickSort(lotto, pivot + 1, right);
}