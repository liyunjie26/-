#include<stdio.h>

void InsertSort(int* arr, int n)
{
	int i;
	for (i = 1; i < n; ++i)//外循环
	{
		int j=i-1;
		int tem = arr[i];
		while (j >= 0 && arr[j]>tem)//找到第一个小于当前位置数据的位置，将待插入数据放置该位置后面
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tem;
	}

}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int i;
	int arr[] = { 2, 5, 1, 4, 9, 8, 7, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, n);
	printArr(arr, n);
	return 0;
}