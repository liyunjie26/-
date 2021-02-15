
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

int partion(int*arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, begin, mid);
	int key = arr[begin];
	while (begin < end)
	{
		if (begin<end&&arr[end]>=key)
			end--;
		arr[begin] = arr[end];
		if (begin < end&&arr[begin] <= key)
			begin++;
		arr[end] = arr[begin];

	}
	arr[begin] = key;
	return begin;
}
void hellSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//确定划分后基准值位置
	int div = partion(arr, begin, end);
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);

}