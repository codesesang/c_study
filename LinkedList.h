#ifndef LINKEDKIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
}Node;

Node* CreateNode(ElementType NewNode);
void DestroyNode(Node* Node);
void AppendNode(Node** _Head, Node* NewNode);
void InsertAfter(Node* Current, Node* NewNode);
void InsertNewHead(Node** _Head, Node* Remove);
void RemoveNode(Node** _Head, Node* Remove);
Node* GetNodeAt(Node* _Head, int Location);
int GetNodeCount(Node* _Head);

#endif 