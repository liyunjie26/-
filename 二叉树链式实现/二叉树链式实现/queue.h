#include<stdio.h>
#include<stdlib.h>
#include"btree.h"
typedef BNode* QDateType;
typedef struct QNode//∂‘¡–
{
	struct QNode* _next;
	QDateType _val;
}QNode;
typedef struct Queue
{
	struct QNode* _head;
	struct QNode* _tail;
	int size;
}Queue;
void initQueue(Queue* q);

QNode* creatNode(QDateType val);

void queuepush(Queue* q, QDateType val);//Œ≤≤Â

void queqePop(Queue* q);//Õ∑…æ

QDateType queueFront(Queue* q);

QDateType queueBack(Queue* q);

int queueEmpty(Queue* q);

int queueSize(Queue* q);
