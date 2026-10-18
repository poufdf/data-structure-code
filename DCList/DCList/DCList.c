#define _CRT_SECURE_NO_WARNINGS
#include"DCList.h"


//申请结点
DCListNode* BuyNode(int x)
{
	DCListNode* newnode = (DCListNode*)malloc(sizeof(DCListNode));
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
// 链表初始化 
DCListNode* DCListInit()
{
	DCListNode* L = BuyNode(-1);
	L->prev = L;
	L->next = L;
	return L;

}

// 销毁链表 
void DCListDestroy(DCListNode* L)
{   
	assert(L);
	DCListNode* cur = L->next;

	while (cur != L)
	{
		DCListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(L);
}
// 打印链表中的元素 
void DCListPrint(DCListNode* L)
{
	assert(L);
	DCListNode* cur = L->next;
	while (cur != L)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

// 获取链表的下标i的结点 
DCListNode* DCListGetElem(DCListNode* L, int i)
{
	assert(L);
	assert(i >= 0);
	DCListNode* cur = L->next;
	int j = 0;
	while (cur != L && j < i)
	{
		cur = cur->next;
		j++;
	}
	assert(j == i && cur != L);
	return cur;
}

// 在pos位置后插⼊值为x的结点 
void DCListInsert(DCListNode* pos, DCLDataType x)
{
	DCListNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next->prev = newnode;
	pos->next = newnode;
	newnode->prev = pos;
}
// 删除pos位置的结点 
void DCListDelete(DCListNode* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
// 头插 
void DCListPushFront(DCListNode* L, DCLDataType x)
{
	DCListInsert(L, x);
}

// 尾插 
void DCListPushBack(DCListNode* L, DCLDataType x)
{
	DCListInsert(L->prev, x);

}

// 头删 
void DCListPopFront(DCListNode* L)
{
	DCListDelete(L->next);
}

// 尾删 
void DCListPopBack(DCListNode* L)
{
	DCListDelete(L->prev);
}