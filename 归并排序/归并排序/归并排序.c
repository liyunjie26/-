/*
归并排序是建立在归并操作上的一种有效的排序算法，该算法是采用分治法的一个非常典型的应用
将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，
再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并

*/


/*
归并：合并有序的子序列，产生更大的有序子序列
分解:把数据按照位置，均衡的分成两个子序列，一个字序列只有一个数据
合并：相邻的有序的子序列进行合并
排序过程吗中需要O(n)的辅助空间

*/



//相邻子序列合并：begin end end+1 end2
//begin   mid   end
void merge(int* arr, int begin, int mid, int end, int* tmp)
{
//递增
	//子区间：[begin,mid][mid+1,end]
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//辅助空间的起始位置
	int idx = begin;
	//合并有序序列
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];

	}
	//判断是否有未合并的元素
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));

	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
//合并之后的序列拷到原始数组的对应区间
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//首先合并子序列
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//合并两个有序的子序列【begin，mid】【mid+1，end】
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n)
{
	int* tmp = (int *)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}



//非递归算法
void mergeSortNor(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	//子序列的步长
	int step = 1;
	while (step < n)
	{
		int idx;
		for (idx = 0; idx < 0; idx += 2 * step)
		{//找到两个待合并的子序列区间
			//[begin，mid]，[mid+1，end]
			int begin = idx;
			int mid = idx + step - 1;
			//判断是否存在第二个子序列
			if (mid >= n - 1)
				continue;
			int end = idx + 2 * step - 1;
			//判断是否越界
			if (end>n - 1)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}
	}
	{

	}

}