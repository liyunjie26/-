/*
prev: ��һ��С�ڻ�׼ֵ��λ��
cur:��һ��С�ڻ�׼ֵ��λ��
��cur�ߵ�С�ڻ�׼ֵ��λ��ʱ����
     �ж�prev��cur�Ƿ�������
		������������䡾prev��cur����ֵ���ǲ����ڻ�׼ֵ������prev��cur��λ��
		��������������䡾prev��cur����ֵ���д����׼ֵ�ģ�����prev���������ݽ���������cur��

*/

/*
ѡȡһ����׼ֵ����ʣ��Ԫ���п�ʼ������
�Ӻ���ǰ�ҵ���һ��С�ڻ�׼ֵ������
��ǰ�����ҵ���һ�����ڻ�׼ֵ������
�����ҵ�������ֵ
�ӽ�����λ�÷ֱ�ʼ�������е�һ��
*/

//�Ż�
//��ȡ�м�λ�õķ���������ȡ��

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
//����ʱ����һ�����ݷ�Χ����С�����Ż�����������滮��һ����Χ�󣬵����������ӿ��ٵ��㷨
int partion(int* arr, int begin, int end)
{
	//��һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = begin + 1;
	int key = arr[begin];
	while (cur < end)
	{
		//��cur�ߵ���һ��С�ڻ�׼ֵ��λ�ã��ж�prev��curʱ������
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
	//ȷ�����ֺ��׼ֵλ��
	int div = partion(arr, begin, end);
	pointSort(arr, begin, div - 1);
	pointSort(arr, div + 1, end);

}