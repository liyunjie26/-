#include<stdio.h>
void selectSort(int* arr, int n)
{
	int start = 0;
	while (start < n - 1)
	{
		int tem = arr[start];
		int point = start;
		for (int i = start + 1; i < n; ++i)
		{
			if (arr[i] < tem)
			{
				tem = arr[i];
				point = i;
			}
		}
		
		arr[point] = arr[start];
		arr[start] = tem;
		start++;
	}
}
void arrPrintf(int*arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 2, 8, 4, 5, 9, 7, 2, 3, 6, 5, 4 };
	int n = sizeof(arr) /sizeof(arr[0]);
	selectSort(arr, n);
	arrPrintf(arr, n);
	return 0;
}