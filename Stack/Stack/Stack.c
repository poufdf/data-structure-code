#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

// 栈的初始化 
void StackInit(Stack* s)
{
	assert(s);
	s->arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (s->arr == NULL)
	{
		printf("空间申请失败");
		exit(-1);
	}
	s->top = 0;
	s->capacity = 4;
}
// 栈的销毁 
void StackDestroy(Stack* s)
{
	assert(s);
	if (s->arr)
	{
		free(s->arr);
		s->arr = NULL;
		s->top = 0;
		s->capacity = 0;
	}
}

// x元素⼊栈(进栈) 
void StackPush(Stack* s, STDataType x)
{    
	assert(s);
	if (s->top == s->capacity)
	{
		STDataType* temp = (STDataType*)realloc(s->arr, sizeof(STDataType) * s->capacity * 2);
		if (temp == NULL)
		{
			printf("申请空间失败");
			exit(-1);
		}
		s->arr = temp;
		s->capacity *= 2;
	}
	s->arr[s->top] = x;
	s->top++;
}

// 将栈顶元素出栈，并⽤返回栈顶元素 
STDataType StackPop(Stack* s)
{    
	assert(s);
	assert(s->arr);
	STDataType x = s->arr[s->top - 1];
	s->top--;
	return x;
}

// 获取栈顶元素并返回 
STDataType StackTop(Stack* s)
{

	assert(s);
	assert(s->arr);
	return s->arr[s->top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* s)
{ 
	assert(s);
	return s->top;
}
// 检测栈是否为空，如果是空返回真，否则返回假 
bool StackEmpty(Stack* s)
{
	return s->top == 0;
}