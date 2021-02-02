#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//假设为小堆
typedef int HDataType;  
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;
void heapInit(heap* hp)//堆初始化
{
	if (hp==NULL)
		return;
	hp->_data = NULL;
	hp->_capacity = hp->_size = 0;
}
void rickle_shiftDown(int* arr, int n, int curPos)//向下调整小堆
{ 
	//左孩子 curPos 为当前位置坐标   以0下标开始
	int child = 2 * curPos + 1;
	while (child < n)
	{

		//从左右孩子找到一个最小值
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curPos])
		{
			int temp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = temp;
			//更新位置
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}
void pile_shiftDown(int* arr, int n, int curPos)//向下调整大堆
{
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] > arr[child])//找出孩子节点最大值
			child = child + 1;
		if (arr[curPos] < arr[child])//如果当前节点小于孩子节点，则进行交换 
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

//建小堆，从最后一个非叶子节点开始走向向下调整,以此往上实际上是向上调整
void rickel_creatHeap(int* arr, int n)      //从最后一个非叶子节点开始
{
	int cosPos = (n - 2) / 2;
	for (; cosPos >= 0; --cosPos)
	{
		//rickle_shiftDown(数组指针，数组元素个数，调整的起始位置)
		rickle_shiftDown(arr, n, cosPos);
	}
}
//建大堆
void pile_creatHeap(int* arr, int n)      //从最后一个非叶子节点开始
{
	int cosPos = (n - 2) / 2;
	for (; cosPos >= 0; --cosPos)
	{
		//rickle_shiftDown(数组指针，数组元素个数，调整的起始位置)
		pile_shiftDown(arr, n, cosPos);
	}
}

//堆元素的插入，采用尾插之后进行调整的规则，若头插则会较大的破坏堆的结构
//插入后不断地与父节点比较并进行交换
//大堆调整
/*
1.首先和父节点进行比较，如果：
			a：大与父节点，交换，更新位置，从父节点位置继续向上看
			b：小于等于父节点
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
//小堆尾插调整
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

void swap(HDataType* a, HDataType* b)//交换函数
{
	HDataType tem = *a;
	*a = *b;
	*b = tem;
}

//检查容量
void cheakCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * (hp->_capacity);
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)*hp->_capacity);
	}
}
//堆的插入
void heapPush(heap* hp, HDataType val)
{
	//检查容量
	cheakCapacity(hp);
	//尾插
	hp->_data[hp->_size] = val;
	//向上调整
	hp->_size++;
	rickle_shiftUp(hp->_data, hp->_size, hp->_size - 1);//假设为小堆
}
//堆元素的删除
/*
即删除最值元素
步骤：
1.首先，将堆顶元素与最后一个叶子元素进行交换
2.之后删除叶子元素
3.进行向下调整
*/
void heapPop(heap* hp)//删除堆顶元素
{
	if (hp == NULL || hp->_size == 0)
		return;
	//交换
	swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	//尾删
	hp->_size--;
	//向下调整
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
	//获取堆顶元素，从小到大排序
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