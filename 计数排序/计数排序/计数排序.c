void CountSort(int* arr, int n)
{
	int max, min;
	max = min = arr[0];
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]>max)
			max = arr[i];

		if (arr[i] < min)
			min = arr[i];
	}
	//计数范围
	int range = max - min + 1;
	//建立一个数组初始化为0
	int* countArr = (int*)calloc(range,sizeof(int));
	//计数
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//遍历计数数组，排序
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[idx++] = i + min;

		}
	}
}