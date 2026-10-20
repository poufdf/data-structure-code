#define _CRT_SECURE_NO_WARNINGS
#include"queue.h"

int main()
{

	LinkQueue q;
	QueueInit(&q);
	EnQueue(&q, 1);
	EnQueue(&q, 2);
	EnQueue(&q, 3);
	EnQueue(&q, 4);
	QueuePrint(&q);
	printf("队列元素个数为：%d\n", QueueSize(&q));
	printf("出队：%d\n", DeQueue(&q));
	QueuePrint(&q);
	printf("队列元素个数为：%d\n", QueueSize(&q));
	printf("队头元素为：%d\n", QueueFront(&q));
	QueueDestroy(&q);
	printf("销毁后队列元素个数为：%d\n", QueueSize(&q));
	return 0;
}