#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"

void Test1()
{
	SqList s;
	SqListInit(&s);
	SqListInsert(&s, 0, 1);
	SqListInsert(&s, 1, 2);
	SqListInsert(&s, 2, 3);
	SqListInsert(&s, 3, 4);
	SqListInsert(&s, 4, 5);
	SqListPrint(&s);
	SqListInsert(&s, 3, 100);
	SqListPrint(&s);
	SqListDestroy(&s);
}
void Test2()
{
	SqList s;
	SqListInit(&s);
	SqListInsert(&s, 0, 1);
	SqListInsert(&s, 1, 2);
	SqListInsert(&s, 2, 3);
	SqListInsert(&s, 3, 4);
	SqListInsert(&s, 4, 5);
	SqListPrint(&s);
	SqDataType x =GetElem(&s, 2);
	printf("%d\n", x);
	int y = LocateElem(&s, 5);
	printf("%d\n", y);

}
void Test3()
{
	SqList s;
	SqListInit(&s);
	SqListInsert(&s, 0, 1);
	SqListInsert(&s, 1, 2);
	SqListInsert(&s, 2, 3);
	SqListInsert(&s, 3, 4);
	SqListInsert(&s, 4, 5);
	int x = SqListSize(&s);
	printf("%d\n", x);
	if (EmptySqList(&s))
	{
		printf("顺序表为空");
	}
	else
	{
		printf("顺序表不为空，元素个数为%d\n", x);
	}
}
void Test4()
{
	SqList s;
	SqListInit(&s);
	SqListInsert(&s, 0, 1);
	SqListInsert(&s, 1, 2);
	SqListInsert(&s, 2, 3);
	SqListInsert(&s, 3, 4);
	SqListInsert(&s, 4, 5);
	SqListPrint(&s);
	int x = SqListDelete(&s, 3);
	SqListPrint(&s);
	printf("%d\n", x);




}





int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}