#define _CRT_SECURE_NO_WARNINGS
#include"DCList.h"

int main()
{
	DCListNode* L = DCListInit();
	DCListPushFront(L, 4);
	DCListPushFront(L, 3);
	DCListPushFront(L, 2);
	DCListPushFront(L, 1);
	DCListPushBack(L, 5);
	DCListPushBack(L, 6);
	DCListPushBack(L, 7);
	DCListPrint(L);
	printf("\n");
	DCListPopFront(L);
	DCListPrint(L);
	printf("\n");
	DCListPopBack(L);
	DCListPrint(L);
	printf("\n");
	DCListInsert(DCListGetElem(L, 1), 100);
	DCListPrint(L);
	DCListDelete(DCListGetElem(L, 1));
	printf("\n");
	DCListPrint(L);
	DCListDestroy(L);
	return 0;
}