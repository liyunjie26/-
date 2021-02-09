#include<stdio.h>
#include"seqList.h"

/*
ѡȡһ����׼ֵ����ʣ��Ԫ���п�ʼ������
�Ӻ���ǰ�ҵ���һ��С�ڻ�׼ֵ������
��ǰ�����ҵ���һ�����ڻ�׼ֵ������
�����ҵ�������ֵ
�ӽ�����λ�÷ֱ�ʼ�������е�һ��
*/

//�Ż�
//��ȡ�м�λ�õķ���������ȡ��


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
{//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//����λ��
	swap(arr, begin, mid);
	//ѡ���׼ֵ
	
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
//Ҫ�ų������Ѿ����������£������ջ�������������
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//ȷ�����ֺ��׼ֵλ��
	int div = partion(arr, begin, end);
	quickSort(arr, begin, div - 1);
	quickSort(arr, div+1, end);

}
//�ǵݹ����
//����ÿһ���µĴ����ֵ�����
void quickSortNor(int *arr, int n)
{
//����һ��˳������潫���ֵ�����
	seqList sq;
	initseqList(&sq);
	//������������
	//�ȷ��ұ����䣬�ڷ��������
	seqListpushBack(&sq, n - 1);
	seqListpushBack(&sq, 0);
	while (!seqListEmpty(&sq))
	{
		//ȡ������
		int left = seqListBack(&sq);
		seqListpopBack(&sq);
		int right = seqListBack(&sq);
		seqListpopBack(&sq);

		//��������
		int div = partion(arr, left, right);

		//[left,div-1]
		if (left < div - 1)//�жϻ���������֮���������������Ԫ��
		{
			seqListpushBack(&sq, div - 1);
			seqListpushBack(&sq, left);

		}
		//[div+1,right]
		if (div+1 < right)//�жϻ���������֮���������������Ԫ��
		{
			seqListpushBack(&sq, right);
			seqListpushBack(&sq, div+1);

		}
	}
}