#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

//交换两个元素
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//打印数组
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//直接插入排序
void InsertSort(int* a, int n)
{
	//外层循环控制排的趟数
	for (int i = 0; i < n - 1; i++)
	{   
		//0-end区间有序，把end+1的值插入到0-end区间，使0-end+1区间有序
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{ 
				break;
			}
		}
		a[end + 1] = temp;
	}
}
//折半插入排序
void MidInsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int left = 0;
		int right = end;
		int key = a[end + 1];
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (key < a[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		//把left-end区间的数据往后挪一位
		for (int j = end; j >= left; j--)
		{
			a[j + 1] = a[j];
		}
		a[right + 1] = key;
	}
}
//希尔排序
void ShellSort(int* a, int n)
{
	int d = n;
	while (d > 1)
	{
		d = d / 3 + 1;
		for (int i = 0; i < n - d; i++)
		{
			int end = i;
			int temp = a[end + d];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + d] = a[end];
					end -= d;
				}
				else
				{
					break;
				}
			}
			a[end + d] = temp;
		}
	}
}
//简单选择排序
void SelectSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{   
		//每次先假设i位置元素的值最小，再和后面的值进行比较
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		//判断是否需要交换
		if (min != i)
		{
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int flag = 0;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//快速排序
int PartitionDigHole(int* a, int left, int right)//用挖坑法处理单趟排序(比基准值大的换到右边去，比基准值小的换到左边来)
{
	int pivotkey = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= pivotkey)
			right--;
		a[left] = a[right];
		while (left < right && a[left] <= pivotkey)
			left++;
		a[right] = a[left];
	}
	a[left] = pivotkey;
	return left;
}
int PartitionLomuto(int* a, int left, int right)//用lomuto法处理单趟排序，设计前后指针,cur的值比基准值小则和++prev的值交换
{
	int pivotkey = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur != right)
	{
		if (a[cur] <= pivotkey)
		 Swap(&a[cur], &a[++prev]);
		cur++;
	}
	Swap(&a[cur], &a[++prev]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int pivotkeyi = PartitionDigHole(a, left, right);
	//int pivotkeyi = PartitionLomuto(a, left, right);//数据量大了不能用lomuto法
	QuickSort(a, left, pivotkeyi - 1);
	QuickSort(a, pivotkeyi + 1, right);
}
//计数排序
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int size = max - min + 1;
	int* count = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		while (count[i]--)
		{
			a[j] = i + min;
			j++;
		}
	}
	free(count);
}
//归并排序
void _MergeSort(int* a, int* temp, int begin, int end)
{   
	//写递归函数第一步先写结束条件
	if (begin == end)
		return;
	int mid = (begin + end) / 2;
	_MergeSort(a, temp, begin, mid);//使左区间有序
	_MergeSort(a, temp, mid + 1, end);//使右区间有序

	int begin1 = begin, end1 = mid;//处理左区间
	int begin2 = mid + 1, end2 = end;//处理右区间
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}
	for (int i = begin; i <=end; i++)
	{
		a[i] = temp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("MergeSort-temp malloc失败");
		exit(-1);
	}
	_MergeSort(a, temp, 0, n - 1);

	free(temp);
	temp = NULL;
}
