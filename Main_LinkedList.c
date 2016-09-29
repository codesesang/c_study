#include "LinkedList.h"

int main(void)
{
	int i = 0;
	int Count = 0;
	Node* Head = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	for (i = 0; i < 5; i++)
	{
		NewNode = CreateNode(i);
		AppendNode(&Head, NewNode);
	}

	NewNode = CreateNode(-1);
	InsertNewHead(&Head, NewNode);

	NewNode = CreateNode(-2);
	InsertNewHead(&Head, NewNode);

	//����Ʈ ���
	Count = GetNodeCount(Head);

	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(Head, i);
		printf("Head[%d] : %d\n", i, Current->Data);
	}

	//����Ʈ�� ������ ��� �ڿ� �� ��� ����

	printf("Inserting 3000 After [2]...\n\n");

	Current = GetNodeAt(Head, 2);
	NewNode = CreateNode(3000);

	InsertAfter(Current, NewNode);

	//����Ʈ ���
	Count = GetNodeCount(Head);

	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(Head, i);
		printf("Head[%d] : %d\n", i, Current->Data);
	}

	//��� ��带 �޸𸮿��� ����
	printf("Destroying Head...\n");

	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(Head, 0);

		if (Current != NULL)
		{
			RemoveNode(&Head, Current);
			DestroyNode(Current);
		}
	}



	return 0;
}