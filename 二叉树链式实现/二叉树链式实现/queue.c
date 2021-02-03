#include"queue.h"
#include<stdlib.h>
#include<stdio.h>
void initQueue(Queue* q)
{
	if (q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->size = 0;
}
QNode* creatNode(QDateType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(QNode));
	node->_next = NULL;
	node->_val = val;
}
void queuepush(Queue* q, QDateType val)//尾插
{
	struct QNode* node = creatNode(val);
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
	q->size++;
}
void queqePop(Queue* q)//头删
{
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode* node = q->_head->_next;
	free(q->_head);
	q->_head = node;
	if (node == NULL)
		q->_tail = NULL;//空对列
	q->size--;
}
QDateType queueFront(Queue* q)
{
	//返回头结点的值
	return q->_head->_val;
}
QDateType queueBack(Queue* q)
{
	return q->_tail->_val;
}
int queueEmpty(Queue* q)
{
	return q->_head == NULL;
}
int queueSize(Queue* q)
{
	return q->size;
}

