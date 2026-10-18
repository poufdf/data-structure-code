#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

//交换两个数据
void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//向上调整算法，建小堆
void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整算法,建大堆
void AdjustDown(HeapDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//默认初始化堆
void HeapInit(Heap* hp)
{
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

//利用给定数组初始化建堆
void HeapInitArray(Heap* hp, HeapDataType* a, int n)
{
	assert(hp);
	assert(a);
	hp->a = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	if (hp->a == NULL)
	{
		printf("HeapInitArray malloc失败");
		exit(-1);
	}
	hp->size = n;
	hp->capacity = n;

	memcpy(hp->a, a, sizeof(HeapDataType) * n);
	//向上调整算法建堆
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(hp->a, i);
	}*/
	//向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, n, i);
	}

}

//堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);//free掉之后要及时置空
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

//堆的插入
void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	//扩容
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HeapDataType* temp = (HeapDataType*)realloc(hp->a, sizeof(HeapDataType) * newcapacity);
		if (temp == NULL)
		{
			printf("HeapPush malloc失败");
			exit(-1);
		}
		hp->a = temp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}

// 堆的删除，删除堆顶数据
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}

// 获取堆顶数据
HeapDataType HeapTop(Heap* hp)
{   
	assert(hp);
	assert(hp->size > 0);
	return hp->a[0];
}

// 判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

//获取堆的数据个数
int HeapSize(Heap* hp)
{   
	assert(hp);
	return hp->size;
}

//堆排序
void HeapSort(int* a, int n)
{
	//先建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//再依次交换堆顶数据和最后一个数据，得到升序的数组
	int j = 1;
	while (j < n)
	{
		Swap(&a[0], &a[n - j]);
		AdjustDown(a, n - j, 0);
		j++;
	}
}