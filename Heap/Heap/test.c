#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

//≤‚ ‘∂—µƒΩ”ø⁄
void HeapTest1()
{
	int a[] = { 1,43,14,15,136,9176,1515,5451,62,145 };
	Heap hp;
	HeapInit(&hp);
	HeapInitArray(&hp, a, sizeof(a) / sizeof(a[0]));
	int k = 0;
	scanf("%d", &k);
	while (!HeapEmpty(&hp) && k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}
//≤‚ ‘∂—≈≈–Ú
void HeapSortTest()
{
	int a[] = { 1,43,14,15,136,9176,1515,5451,62,145 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	HeapTest1();
	printf("\n");
	HeapSortTest();
	return 0;
}