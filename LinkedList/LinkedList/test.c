#define _CRT_SECURE_NO_WARNINGS
#include"LinkedList.h"

void Test1()
{
	LNode* L = ListInit();
	ListPushBack(L, 1);
	ListPushBack(L, 2);
	ListPushBack(L, 3);
	ListPushBack(L, 4);
	ListPushFront(L, 5);
	ListPopFront(L);
	ListPopBack(L);
	ListPushBack(L, 4);
	ListPrint(L);
	//printf("%d", ListSize(L));
	ListInsert(L, 1, 6);
	ListPrint(L);
	ListDelete(L, 1);
	ListPrint(L);
	LNode* p1 = ListLocateElem(L, 2);
	printf("%p\n", p1);
	LNode* p2 = ListGetElem(L, 1);
	printf("%p\n", p2);
	if (!ListEmpty(L))
	{
		printf("链表非空\n");
	}
	ListDestroy(L);
	if (ListEmpty)
	{
		printf("链表为空");
	}

}
int main()
{

	Test1();
	return 0;
}

