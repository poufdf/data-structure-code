#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int LDataType;
typedef struct ListNode
{
	LDataType data;
	struct Listnode* next;
}LNode;


// 创建⼀个新结点
LNode* BuyListNode(int data);

// 初始化链表
LNode* ListInit();

//打印链表
void ListPrint(LNode* L);

// 获取链表中有效元素个数
int ListSize(LNode* L);

// 获取链表中第⼀个数据等于x结点的地址，若不存在返回NULL指针
LNode* ListLocateElem(LNode* L, LDataType x);

// 返回链表中下标为i的结点
LNode* ListGetElem(LNode* L, int i);

// 在链表的第i个下标位置插⼊元素x
void ListInsert(LNode* L, int i, LDataType x);

// 删除链表中下标为i的结点
void  ListDelete(LNode* L, int i);

// 检测链表是否为空，空返回真，否则返回假
bool ListEmpty(LNode* L);

// 头插
void ListPushFront(LNode* L, LDataType x);

// 尾插
void ListPushBack(LNode * L, LDataType x);

//头删
LDataType ListPopFront(LNode* L);

// 尾删
LDataType ListPopBack(LNode* L);

// 销毁链表
void ListDestroy(LNode* L);
