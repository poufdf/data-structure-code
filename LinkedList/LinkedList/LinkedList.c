#define _CRT_SECURE_NO_WARNINGS
#include"LinkedList.h"

//创建新结点
LNode* BuyListNode(int data)
{
	LNode* newnode = (LNode*)malloc(sizeof(LNode));
	if (newnode == NULL)
	{
		printf("创建新结点失败");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}
//初始化链表
LNode* ListInit()
{
	LNode* newnode = BuyListNode(-1);

	return newnode;
}
//打印链表
void ListPrint(LNode* L)
{
	assert(L);
	LNode* cur = L->next;
	printf("头结点->");
	while (cur->next)
	{
		printf("%d->", cur->data);
		cur = cur->next;

	}
	printf("%d->", cur->data);
	printf("NULL\n");
}
//链表中元素个数
int ListSize(LNode* L)
{
	int size = 0;
	if (L -> next == NULL)
	{
		return size;
	}
	else
	{
		LNode* cur = L;
		while (cur->next)
		{
			size++;
			cur = cur->next;
		}
		return size;
	}
}
// 获取链表中第⼀个数据等于x结点的地址，若不存在返回NULL指针

LNode* ListLocateElem(LNode* L, LDataType x)
{
	LNode* cur = L->next;
	while (cur->next)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;

}
// 返回链表中下标为i的结点
LNode* ListGetElem(LNode* L, int i)
{    
	assert(i >= 0);
	int j = 0;
	LNode* cur = L->next;
	while (cur != NULL && j < i)
	{
		cur = cur->next;
		j++;
	}
	return cur;
}
// 在链表的第i个下标位置插⼊元素x
void ListInsert(LNode* L, int i, LDataType x)
{
	int j = -1;
	LNode* cur = L;
	while (cur != NULL && j < i - 1)
	{
		cur = cur->next;
		j++;
	}
	assert(cur != NULL);
	LNode* newnode = BuyListNode(x);
	newnode->next = cur->next;
	cur->next = newnode;

}
// 删除链表中下标为i的结点，并⽤x带出结点的值

void ListDelete(LNode* L, int i)
{
	int j = -1;
	LNode* cur = L;
	while (cur->next != NULL && j < i - 1)
	{
		cur = cur->next;
		j++;
	}
	assert(cur->next != NULL);
	LNode* iNode = cur->next;
	cur->next = iNode->next;
	free(iNode);
}
// 检测链表是否为空，空返回真，否则返回假
bool ListEmpty(LNode* L)
{
	return L->next == NULL;

}
//头插
void ListPushFront(LNode* L, LDataType x)
{
	LNode* newnode = BuyListNode(x);
	LNode* cur = L;
	newnode->next = cur->next;
	cur->next = newnode;
}
// 尾插
void ListPushBack(LNode* L, LDataType x)
{
	LNode* cur = L;
	while (cur->next)
	{
		cur = cur->next;
	}
	LNode* newnode = BuyListNode(x);
	newnode->next = cur->next;
	cur->next = newnode;
}

//头删
LDataType ListPopFront(LNode* L) 
{
	LNode* cur = L;
	LNode* iNode = cur->next;
	cur->next = iNode->next;
	free(iNode);
}
// 尾删
LDataType ListPopBack(LNode* L)
{
	LNode* ptai = L;
	LNode* cur = L->next;
	while (cur->next)
	{
		ptai = cur;
		cur = cur->next;
	}
	ptai->next = cur->next;
	free(cur);
}
// 销毁链表
void ListDestroy(LNode* L)
{
	LNode* cur = L->next;
	while (cur)
	{
		LNode* next = cur->next;
		free(cur);
		cur = next;

	}
	free(L);
}
