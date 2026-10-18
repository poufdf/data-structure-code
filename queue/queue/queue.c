#define _CRT_SECURE_NO_WARNINGS
#include"queue.h"

// 初始化队列 
void QueueInit(LinkQueue* q)
{
	q->front = q->rear = (QNode*)malloc(sizeof(QNode));
	if (q->front == NULL)
	{
		printf("初始化失败");
		exit(-1);
	}
	q->front->next = NULL;
	q->size = 0;
}

// 销毁队列 
void QueueDestroy(LinkQueue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}


// 检测队列是否为空，空返回真，否则返回假 
bool QueueEmpty(LinkQueue* q)
{
	return q->size == 0;

}

// 获取队列中有效元素个数 
int QueueSize(LinkQueue* q)
{
	return q->size;
}

// 获取队头元素 
QDataType QueueFront(LinkQueue* q)\
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->next->data;
}
// 将x⼊队列 
void EnQueue(LinkQueue* q, QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("EnQueue:申请结点失败");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	q->rear->next = newnode;
	q->rear = newnode;
	q->size++;
}
// 出队并返回队头数据 
QDataType DeQueue(LinkQueue* q)
{
	QNode* delnode = q->front->next;
	QDataType x = delnode->data;
	q->front->next = delnode->next;
	free(delnode);
	delnode = NULL;
	q->size--;
	if (q->front->next == NULL)
	{
		q->rear = q->front;
	}
	return x;

}

//打印队列数据
void QueuePrint(LinkQueue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* cur = q->front->next;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");


}