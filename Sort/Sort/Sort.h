#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//交换两个元素
void Swap(int* a, int* b);
//打印数组
void PrintArray(int* a, int n);
//直接插入排序
void InsertSort(int* a, int n);
//折半插入排序
void MidInsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);
//简单选择排序
void SelectSort(int* a, int n);
//堆排序在堆那个章节有写，这里就省略了
//冒泡排序(最大的一个数像泡泡一样往后冒，所以叫冒泡排序，令人忍俊不禁)
void BubbleSort(int* a, int n);
//快速排序
int PartitionDigHole(int* a, int left, int right);//用挖坑法处理单趟排序(比基准值大的换到右边去，比基准值小的换到左边来)
int PartitionLomuto(int* a, int left, int right);//用lomuto法处理单趟排序，设计前后指针,cur的值比基准值小则和++prev的值交换
void QuickSort(int* a, int left, int right);
//计数排序
void CountSort(int* a, int n);
//归并排序
void MergeSort(int* a, int n);
