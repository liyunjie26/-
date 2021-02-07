void bubbleSort(int* arr, int n)
{
	int end = n;
	while (end > 1)
	{//标记是否发生交换操作
		int flag = 0;
		for (int i = 0; i < end-1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				flag = 1;
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}

		}
		if (flag == 0)
			break; 
		end--;
	}


}