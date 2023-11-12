#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int DataType;
struct seqQueue { 
	int MAXINUM;
	//记录插入点和输出点
	int front, rear;
	DataType* q;
};
typedef struct seqQueue *PseqQueue;

PseqQueue createNullQueue_seq(int m) {
	/*若m=0，则返回NULL*/
	if (m == 0) return NULL;
	/*创建一个空的顺序队列*/
	PseqQueue palist = (PseqQueue)malloc(sizeof(struct seqQueue));
	if (palist != NULL) {
		palist->q = (DataType*)malloc(sizeof(DataType) * m);
		if (palist->q) {
			/*能存放的最大元素个数为 m*/
			palist->MAXINUM = m;
			palist->front = 0;
			palist->rear = 0;
			return palist;
		} else {
			free(palist);
		}
	}
	return NULL;
}

int isNullQueue_seq(PseqQueue Q) {
	/*判断顺序（环形）队列是否为空，若为空，返回值为1*/
	if (Q == NULL) return -1;
	/*若队列不存在，则返回-1*/
	if (Q->front == Q->rear) return 1;
	else return 0;
}

int isFullQueue_seq(PseqQueue Q) {
	/*判断环形队列是否已满，若已满，返回值为1*/
	if ((Q->rear + 1) % (Q->MAXINUM) == Q->front) return 1;
	return 0;
}

int enQueue_seq(PseqQueue Q, DataType x) {
	//在环形队列中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
	int q = isFullQueue_seq(Q);
	if (!q) {
		Q->q[Q->rear] = x;
		Q->rear = (Q->rear + 1) % (Q->MAXINUM);
		return 1;
	} else return 0;
}

DataType delQueue_seq(PseqQueue Q) {
	//出队并返回删除元素，若队列为空，则返回-1
	if (Q->front == Q->rear) return -1;
	else {
		int m = Q->q[Q->front];
		Q->front = (Q->front + 1) % (Q->MAXINUM);
		return m;
	}
}

DataType front_seq(PseqQueue Q) {
	// 取队首元素返回，若队列为空，则返回-1
	if (Q->front == Q->rear) return -1;
	else return Q->q[Q->front];
}

//销毁顺序队列，释放队列所占存储空间
int destroyQueue_seq(PseqQueue Q) {
	//返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
	if (Q == NULL) return 0;
	else {
		int num = Q->front + 1;
		Q->MAXINUM = 0;
		free(Q->q);
		return num;
	}
}
