#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

void TestPerformance() {
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);
	int* a9 = (int*)malloc(sizeof(int) * N);
	int* a10 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i) {
		a1[i] = rand() + i;
		//a1[i] = rand(); // 重复数据较多 
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
		a10[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N); 
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N); 
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N); 
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N); 
	int end4 = clock();

	int begin5 = clock();
	//BubbleSort(a5, N); 
	int end5 = clock();

	int begin6 = clock();
	QuickSort(a6, 0, N - 1); 
	int end6 = clock();

	int begin7 = clock();
	MergeSort(a7, N); 
	int end7 = clock();

	int begin8 = clock();
	CountSort(a8, N); 
	int end8 = clock();

	int begin9 = clock();
	//RadixSortLSD(a9, N); 
	int end9 = clock();

	int begin10 = clock();
	MidInsertSort(a10, N); 
	int end10 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("MidInserSort:%d\n", end10 - begin10);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end5 - begin5);
	printf("QuickSort:%d\n", end6 - begin6);
	printf("MergeSort:%d\n", end7 - begin7);
	printf("CountSort:%d\n", end8 - begin8);
	printf("RadixSortLSD:%d\n", end9 - begin9);
	
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
	free(a10);
}

void TestInsertSort()
{
	int a[] = { 11,9,35,23,16,13,16,1,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestMidInsertSort()
{
	int a[] = { 11,9,35,23,16,13,16,1,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MidInsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestShellSort()
{
	int a[] = { 11,9,35,23,16,13,16,1,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestSelectSort()
{
	int a[] = { 11,9,35,23,16,13,16,1,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestBubbleSort()
{
	int a[] = { 11,9,35,23,16,13,16,1,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestQuickSort()
{
	int a[] = { 11,9,35,23,16,13,16,1,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a,0, sizeof(a) / sizeof(a[0])-1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestCountSort()
{
	int a[] = { 11,94,35,23,16,13,16,11,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestMergeSort()
{
	int a[] = { 11,9,35,23,16,13,16,1,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	TestPerformance();
	//TestInsertSort();
	//TestMidInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestCountSort();
	//TestMergeSort();
	return 0;
}