#include<stdio.h>
#include<random>
void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{//���һ��������������1����֤�������ݶ���ͬһ��
		gap = gap / 3 +1;
		int i = gap;
		for (; i < n; ++i)//ʵ����ȷ��gap�����С�����в�������
		{//ͬһ���������һ����������λ��
			int end = i - gap;
			//�����������
			int data = arr[i];
			while (end >= 0 && arr[end]>data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}
void printArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
} 
void main()
{
	int arr[] = { 10, 1,3,2,0,7,5,4,6,8,9};
	int n = sizeof(arr) / sizeof(arr[0]);
	shellSort(arr, n);
	printArr(arr, n);
	printf("\n");


}