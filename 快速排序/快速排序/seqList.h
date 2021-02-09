//数组  数组先关信息： 有效元素个数，数组的容量
//静态顺序表
#define N 100
typedef int SLDDataType;
struct seqList1
{
	SLDDataType _data[N];
	int _size;
};

typedef struct seqList
{
	SLDDataType* _data;
	int _size;
	int _capacity;
}seqList;
SLDDataType seqListBack(seqList* sl);
void initseqList(seqList *);
//操作：增删查改
//尾插：给顺序表的最后一个有效数据末尾插入新的数据
void seqListCheckCapacity(seqList* sl);//检查容量
void seqListpushBack(seqList* sl, SLDDataType val);
void seqListpopBack(seqList* sl);
void seqLstPrint(seqList* sl);
SLDDataType seqListAt(seqList* sl, int pos);
int seqListEmpty(seqList* sl);
int seqListSize(seqList* sl);
void seqListPushFront(seqList* sl, SLDDataType val);//头插
void seqListPopFront(seqList* sl, SLDDataType val);//头删
void seqListPopFront(seqList* sl, SLDDataType val);//头删
void seqListInsert(seqList* sl, int pos, SLDDataType val);//任意位置插入数据
void seqListFind(seqList* sl, SLDDataType val);//查找某一元素
void seqListDestroy(seqList* sl);//销毁



