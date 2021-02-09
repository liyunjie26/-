#include<String.h>
#include<stdio.h>
#include"seqList.h"
#include<memory.h>
void initseqList(seqList *sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_capacity = 0;
	sl->_size = 0;
}
void seqListCheckCapacity(seqList* sl)//检查容量
{
	if (sl->_capacity == sl->_size)
	{
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		SLDDataType *tmp = (SLDDataType*)malloc(newCapacity*sizeof(SLDDataType));
		memcpy(tmp, sl->_data, sizeof(SLDDataType)*sl->_size);
		free(sl->_data);
		sl->_data = tmp;
		sl->_capacity = newCapacity;
	}
}
void seqListpushBack(seqList* sl, SLDDataType val)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);//检查容量
	sl->_data[sl->_size] = val;
	sl->_size++;
}
void seqListPopFront(seqList* sl, SLDDataType val) //头删
{
	if (sl == NULL)
		return;
	int start = 1;
	while (start<sl->_size)
	{
		sl->_data[start - 1] = sl->_data[start];
		start++;
	}
}

void seqListpopBack(seqList* sl)
{
	if (sl == NULL)
		return;
	if (sl->_size > 0)
		sl->_size--;
}
void seqLstPrint(seqList* sl)
{
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->_size; ++i)
	{
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}
SLDDataType seqListAt(seqList* sl, int pos)
{
	return sl->_data[pos];

}
int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
		return 0;
	else
		return 1;
}
int seqListSize(seqList* sl)
{

	if (sl == NULL || sl->_size == 0)
		return 0;
	else
		return sl->_size;
}

void seqListPushFront(seqList* sl, SLDDataType val)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);
	int end = sl->_size;
	while (end>0)
	{
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	sl->_data[0] = val;
	sl->_size++;
}
void seqListInsert(seqList* sl, int pos, SLDDataType val)//任意位置插入数据

{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);
	if (pos >= 0 && pos <= sl->_size)
	{

		int end = sl->_size;
		while (end > pos)
		{
			sl->_data[end] = sl->_data[end - 1];
			--end;
		}
		sl->_data[pos] = val;
		sl->_size++;
	}
}
void seqListErase(seqList* sl, int pos)
{
	if (sl == NULL || sl->_size == 0)
		return;
	if ((0 <= pos) && (pos < sl->_size))
	{
		int start = pos + 1;
		while (start < sl->_size)
		{
			sl->_data[start - 1] = sl->_data[start];
			++start;
		}
	}
	sl->_size--;
}
void seqListFind(seqList* sl, SLDDataType val)//查找某一元素
{
	if (sl == NULL || sl->_size == 0)
		return;
	int start = 0;
	while (start < sl->_size)
	{
		if (sl->_data[start] == val)
		{
			printf("have found at %d", start);
			return;
		}
		start++;
	}
	if (start == sl->_size)
	{
		printf("not found\n");
		return;
	}

}
void seqListDestroy(seqList* sl)//销毁
{
	if (sl != NULL&&sl->_data != NULL)
	{
		free(sl->_data);
		sl->_data = NULL;
	}

}

void test()
{
	seqList sl;
	initseqList(&sl);
	seqListInsert(&sl, 0, 0);
	seqListInsert(&sl, 1, 1);
	seqListInsert(&sl, 2, 3);
	seqListInsert(&sl, 3, 4);
	seqListInsert(&sl, 4, 5);
	seqListInsert(&sl, 5, 6);
	seqListErase(&sl, 1);
	seqLstPrint(&sl);

}
int main()
{
	test();
	return 0;
}
SLDDataType seqListBack(seqList* sl)
{
	return sl->_data[sl->_size - 1];
}