#include<stdio.h>
#include"seqList.h"

/*
选取一个基准值，从剩余元素中开始遍历：
从后往前找到第一个小于基准值的数据
从前往后找到第一个大于基准值的数据
交换找到的两个值
从交换的位置分别开始继续进行第一步
*/

//优化
//获取中间位置的方法：三数取中


int getMid(int* arr, int begin, int end)
{
	int mid = (end - begin) / 2 + begin;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin; 
	}
	else
	{
		if (arr[mid] < arr[end])//begin<mid
			return mid;
		else if (arr[begin]>arr[end])
			return begin;
		else
			return end;
	}
}
void swap(int* arr, int begin, int end)
{
	int temp = arr[begin];
	arr[begin] = arr[end];
	arr[end] = temp;
}

int partion(int* arr, int begin, int end)
{//获取基准值的位置
	int mid = getMid(arr, begin, end);
	//交换位置
	swap(arr, begin, mid);
	//选择基准值
	
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{

		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		swap(arr, begin, end);
		
	}
	swap(arr, start, begin);
	return begin;
}
//要排除数组已经有序的情况下，会造成栈溢出，发生错误
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//确定划分后基准值位置
	int div = partion(arr, begin, end);
	quickSort(arr, begin, div - 1);
	quickSort(arr, div+1, end);

}
//非递归快排
//保存每一个新的带划分的区间
void quickSortNor(int *arr, int n)
{
//创建一个顺序表，保存将划分的区间
	seqList sq;
	initseqList(&sq);
	//保存整个区间
	//先放右边区间，在放左边区间
	seqListpushBack(&sq, n - 1);
	seqListpushBack(&sq, 0);
	while (!seqListEmpty(&sq))
	{
		//取出区间
		int left = seqListBack(&sq);
		seqListpopBack(&sq);
		int right = seqListBack(&sq);
		seqListpopBack(&sq);

		//划分区间
		int div = partion(arr, left, right);

		//[left,div-1]
		if (left < div - 1)//判断划分完区间之后左边至少有两个元素
		{
			seqListpushBack(&sq, div - 1);
			seqListpushBack(&sq, left);

		}
		//[div+1,right]
		if (div+1 < right)//判断划分完区间之后左边至少有两个元素
		{
			seqListpushBack(&sq, right);
			seqListpushBack(&sq, div+1);

		}
	}
}