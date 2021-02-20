/*
�鲢�����ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨�����㷨�ǲ��÷��η���һ���ǳ����͵�Ӧ��
��������������кϲ����õ���ȫ��������У�����ʹÿ������������
��ʹ�����жμ������������������ϲ���һ���������Ϊ��·�鲢

*/


/*
�鲢���ϲ�����������У��������������������
�ֽ�:�����ݰ���λ�ã�����ķֳ����������У�һ��������ֻ��һ������
�ϲ������ڵ�����������н��кϲ�
�������������ҪO(n)�ĸ����ռ�

*/



//���������кϲ���begin end end+1 end2
//begin   mid   end
void merge(int* arr, int begin, int mid, int end, int* tmp)
{
//����
	//�����䣺[begin,mid][mid+1,end]
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//�����ռ����ʼλ��
	int idx = begin;
	//�ϲ���������
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];

	}
	//�ж��Ƿ���δ�ϲ���Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));

	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
//�ϲ�֮������п���ԭʼ����Ķ�Ӧ����
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//���Ⱥϲ�������
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//�ϲ���������������С�begin��mid����mid+1��end��
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n)
{
	int* tmp = (int *)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}



//�ǵݹ��㷨
void mergeSortNor(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	//�����еĲ���
	int step = 1;
	while (step < n)
	{
		int idx;
		for (idx = 0; idx < 0; idx += 2 * step)
		{//�ҵ��������ϲ�������������
			//[begin��mid]��[mid+1��end]
			int begin = idx;
			int mid = idx + step - 1;
			//�ж��Ƿ���ڵڶ���������
			if (mid >= n - 1)
				continue;
			int end = idx + 2 * step - 1;
			//�ж��Ƿ�Խ��
			if (end>n - 1)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}
	}
	{

	}

}