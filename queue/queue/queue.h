#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct LinkedQueue
{
	QNode* front;
	QNode* rear;
	int size;
}LinkQueue;

// 初始化队列 
void QueueInit(LinkQueue* q);

// 销毁队列 
void QueueDestroy(LinkQueue* q);

// 检测队列是否为空，空返回真，否则返回假 
bool QueueEmpty(LinkQueue* q);

// 获取队列中有效元素个数 
int QueueSize(LinkQueue* q);

// 获取队头元素 
QDataType QueueFront(LinkQueue* q);

// 将x⼊队列 
void EnQueue(LinkQueue* q, QDataType x);

// 出队并返回队头数据 
QDataType DeQueue(LinkQueue* q);

//打印队列数据
void QueuePrint(LinkQueue* q);


