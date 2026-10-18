#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	STDataType x = StackTop(&s);
	printf("%d\n", x);
	STDataType y = StackPop(&s);
	printf("%d\n", y);
	STDataType z = StackPop(&s);
	printf("%d\n", z);
	int size = StackSize(&s);
	printf("%d\n", size);
	return 0;
}