/*
prev: 上一个小于基准值的位置
cur:下一个小于基准值的位置
当cur走到小于基准值的位置时，则：
     判断prev与cur是否连续：
		如果连续：区间【prev，cur】的值都是不大于基准值，更新prev与cur的位置
		如果不连续：区间【prev，cur】的值，有大与基准值的，更新prev，进行数据交换，更新cur；

*/

/*
选取一个基准值，从剩余元素中开始遍历：
从后往前找到第一个小于基准值的数据
从前往后找到第一个大于基准值的数据
交换找到的两个值
从交换的位置分别开始继续进行第一步
*/

//优化
//获取中间位置的方法：三数取中

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
//排序时可在一定数据范围进行小区间优化，即当区间规划到一定范围后，调用其他更加快速的算法
int partion(int* arr, int begin, int end)
{
	//上一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = begin + 1;
	int key = arr[begin];
	while (cur < end)
	{
		//当cur走到下一个小于基准值的位置，判断prev和cur时候连续
		if (arr[cur] < key && ++prev != cur)
		{
			swap(arr, prev, cur);
		}
		cur++;
	}
	swap(arr, begin, prev);
	return prev;
}

void pointSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//确定划分后基准值位置
	int div = partion(arr, begin, end);
	pointSort(arr, begin, div - 1);
	pointSort(arr, div + 1, end);

}