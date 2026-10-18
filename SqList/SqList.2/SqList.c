#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"


//初始化
void SqListInit(SqList* ps)
{
	assert(ps);
	ps->arr = (SqDataType*)malloc(sizeof(SqDataType) * 4);
	if (ps->arr == NULL)
	{
		printf("初始化失败");
		//exit(-1);
		return;
	}
	ps->size = 0;
	ps->capacity = 4;
}

//销毁
void SqListDestroy(SqList* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;

	}
	ps->size = 0;
	ps->capacity = 0;
}
//插入
void SqListInsert(SqList* ps, int i, SqDataType x)
{
	assert(ps);
	assert(i >= 0 && i <= ps->size);
	if (ps->size == ps->capacity)
	{
		SqDataType* temp = (SqDataType*)realloc(ps->arr, sizeof(SqDataType) * ps->capacity * 2);
		if (temp == NULL)                      //这里犯错了，注意这里传的是ps->arr,而不是结构体(这里操作的顺序表是ps结构体里的arr数组)
		{
			printf("扩容失败");
			return;
		}
		ps->arr = temp;
		ps -> capacity *= 2;

	}

	for (int j = ps->size - 1; j >= i; j--)
	{
		ps->arr[j + 1] = ps->arr[j];
	}
	ps->arr[i] = x;
	ps->size++;
}
//删除第i个元素，并返回删除的值
SqDataType SqListDelete(SqList* ps, int i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);
	SqDataType x = ps->arr[i];
	if (i == ps->size - 1)
	{
		ps->size--;
		return x;
	}
	else
	{
		for (int j = i; j < ps->size - 1; j++)
		{
			ps->arr[j] = ps->arr[j + 1];
		}
		ps->size--;
		return x;

	}
	
}






//打印
void SqListPrint(SqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
		
	}
	printf("\n");
}
//返回下标为i的元素
SqDataType GetElem(SqList* ps, int i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);
	return ps->arr[i];
}
//返回元素第一个为x的下标，不存在返回-1
int LocateElem(SqList* ps, SqDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}
//判空
bool EmptySqList(SqList* ps)
{
	return ps->size == 0;
}
//返回元素个数
int SqListSize(SqList* ps)
{
	return ps->size;
}