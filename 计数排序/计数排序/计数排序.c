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
	//������Χ
	int range = max - min + 1;
	//����һ�������ʼ��Ϊ0
	int* countArr = (int*)calloc(range,sizeof(int));
	//����
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//�����������飬����
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[idx++] = i + min;

		}
	}
}