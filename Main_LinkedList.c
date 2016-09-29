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

	//리스트 출력
	Count = GetNodeCount(Head);

	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(Head, i);
		printf("Head[%d] : %d\n", i, Current->Data);
	}

	//리스트의 세번쨰 노드 뒤에 새 노드 삽입

	printf("Inserting 3000 After [2]...\n\n");

	Current = GetNodeAt(Head, 2);
	NewNode = CreateNode(3000);

	InsertAfter(Current, NewNode);

	//리스트 출력
	Count = GetNodeCount(Head);

	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(Head, i);
		printf("Head[%d] : %d\n", i, Current->Data);
	}

	//모든 노드를 메모리에서 제거
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