#include "LinkedList.h"


Node* CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* Node)
{
	free(Node);
}

void AppendNode(Node** _Head, Node* NewNode)
{
	if ((*_Head) == NULL)
	{
		*_Head = NewNode;
	}

	else
	{
		Node* Tail = (*_Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

void InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void InsertNewHead (Node** _Head, Node* NewHead)
{
	if (*_Head == NULL)
	{
		(*_Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*_Head);
		(*_Head) = NewHead;
	}
}

void RemoveNode(Node** _Head, Node* Remove)
{
	if (*_Head == Remove)
	{
		*_Head = Remove->NextNode;
	}

	else
	{
		Node* Current = *_Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}
	
		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

Node* GetNodeAt(Node* _Head, int Location)
{
	Node* Current = _Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

int GetNodeCount(Node* _Head)
{
	int count = 0;
	Node* Current = _Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		count++;
	}

	return count;
}
