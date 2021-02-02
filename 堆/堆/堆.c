#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//����ΪС��
typedef int HDataType;  
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;
void heapInit(heap* hp)//�ѳ�ʼ��
{
	if (hp==NULL)
		return;
	hp->_data = NULL;
	hp->_capacity = hp->_size = 0;
}
void rickle_shiftDown(int* arr, int n, int curPos)//���µ���С��
{ 
	//���� curPos Ϊ��ǰλ������   ��0�±꿪ʼ
	int child = 2 * curPos + 1;
	while (child < n)
	{

		//�����Һ����ҵ�һ����Сֵ
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//��Ҫ���������ݺ���Сֵ���бȽ�
		if (arr[child] < arr[curPos])
		{
			int temp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = temp;
			//����λ��
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}
void pile_shiftDown(int* arr, int n, int curPos)//���µ������
{
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] > arr[child])//�ҳ����ӽڵ����ֵ
			child = child + 1;
		if (arr[curPos] < arr[child])//�����ǰ�ڵ�С�ں��ӽڵ㣬����н��� 
		{
			int temp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = temp;
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}

//��С�ѣ������һ����Ҷ�ӽڵ㿪ʼ�������µ���,�Դ�����ʵ���������ϵ���
void rickel_creatHeap(int* arr, int n)      //�����һ����Ҷ�ӽڵ㿪ʼ
{
	int cosPos = (n - 2) / 2;
	for (; cosPos >= 0; --cosPos)
	{
		//rickle_shiftDown(����ָ�룬����Ԫ�ظ�������������ʼλ��)
		rickle_shiftDown(arr, n, cosPos);
	}
}
//�����
void pile_creatHeap(int* arr, int n)      //�����һ����Ҷ�ӽڵ㿪ʼ
{
	int cosPos = (n - 2) / 2;
	for (; cosPos >= 0; --cosPos)
	{
		//rickle_shiftDown(����ָ�룬����Ԫ�ظ�������������ʼλ��)
		pile_shiftDown(arr, n, cosPos);
	}
}

//��Ԫ�صĲ��룬����β��֮����е����Ĺ�����ͷ�����ϴ���ƻ��ѵĽṹ
//����󲻶ϵ��븸�ڵ�Ƚϲ����н���
//��ѵ���
/*
1.���Ⱥ͸��ڵ���бȽϣ������
			a�����븸�ڵ㣬����������λ�ã��Ӹ��ڵ�λ�ü������Ͽ�
			b��С�ڵ��ڸ��ڵ�
*/

void pile_shiftUp(int* arr, int n, int curPos)
{
	int parent = (curPos - 1) / 2;
	while (curPos > 0)
	{

		if (arr[curPos] > arr[parent])
		{
			int temp = arr[parent];
			arr[parent] = arr[curPos];
			arr[curPos] = temp;
			curPos = parent;
			parent = (curPos - 1) / 2;
		}
		else
			break;

	}
}
//С��β�����
void rickle_shiftUp(int* arr, int n, int curPos)
{
	int parent = (curPos - 1) / 2;
	while (curPos > 0)
	{

		if (arr[curPos] < arr[parent])
		{
			int temp = arr[parent];
			arr[parent] = arr[curPos];
			arr[curPos] = temp;
			curPos = parent;
			parent = (curPos - 1) / 2;
		}
		else
			break;

	}
}

void swap(HDataType* a, HDataType* b)//��������
{
	HDataType tem = *a;
	*a = *b;
	*b = tem;
}

//�������
void cheakCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * (hp->_capacity);
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)*hp->_capacity);
	}
}
//�ѵĲ���
void heapPush(heap* hp, HDataType val)
{
	//�������
	cheakCapacity(hp);
	//β��
	hp->_data[hp->_size] = val;
	//���ϵ���
	hp->_size++;
	rickle_shiftUp(hp->_data, hp->_size, hp->_size - 1);//����ΪС��
}
//��Ԫ�ص�ɾ��
/*
��ɾ����ֵԪ��
���裺
1.���ȣ����Ѷ�Ԫ�������һ��Ҷ��Ԫ�ؽ��н���
2.֮��ɾ��Ҷ��Ԫ��
3.�������µ���
*/
void heapPop(heap* hp)//ɾ���Ѷ�Ԫ��
{
	if (hp == NULL || hp->_size == 0)
		return;
	//����
	swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	//βɾ
	hp->_size--;
	//���µ���
	rickle_shiftDown(hp->_data, hp->_size, 0);
}
int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}
HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}
void heapdel(heap *hp)
{
	free(hp->_data);
	free(hp);
}
void test()
{
	heap hp;
	heapInit(&hp);
	heapPush(&hp, 28);
	heapPush(&hp, 2);
	heapPush(&hp, 39);
	heapPush(&hp, 24);
	heapPush(&hp, 98);
	heapPush(&hp, 21);
	heapPush(&hp, 10);
	//��ȡ�Ѷ�Ԫ�أ���С��������
	while (!heapEmpty(&hp))
	{
		printf("%d  ", heapTop(&hp));
		heapPop(&hp);
	}
	//int arr[] = { 10, 5, 3, 8, 7, 6 };
	//rickle_shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
	
}
int main()
{
	test();
	return 0;
}