#include<stdio.h>

void InsertSort(int* arr, int n)
{
	int i;
	for (i = 1; i < n; ++i)//��ѭ��
	{
		int j=i-1;
		int tem = arr[i];
		while (j >= 0 && arr[j]>tem)//�ҵ���һ��С�ڵ�ǰλ�����ݵ�λ�ã������������ݷ��ø�λ�ú���
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