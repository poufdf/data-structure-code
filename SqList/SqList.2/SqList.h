#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef int SqDataType;
typedef struct SequenceList
{
	SqDataType* arr;
	int size;
	int capacity;
}SqList;

//初始化
void SqListInit(SqList* ps);
//销毁
void SqListDestroy(SqList* ps);
//在第i个位置插入元素x
void SqListInsert(SqList* ps, int i, SqDataType x);
//删除第i个元素，并返回删除的值
SqDataType SqListDelete(SqList* ps, int i);
//打印
void SqListPrint(SqList* ps);
//返回下标为i的元素
SqDataType GetElem(SqList* ps, int i);
//返回元素第一个为x的下标，不存在返回-1
int LocateElem(SqList* ps, SqDataType x);
//判空
bool EmptySqList(SqList* ps);
//返回元素个数
int SqListSize(SqList* ps);

