#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int DataType;
struct seqQueue { 
	int MAXINUM;
	//��¼�����������
	int front, rear;
	DataType* q;
};
typedef struct seqQueue *PseqQueue;

PseqQueue createNullQueue_seq(int m) {
	/*��m=0���򷵻�NULL*/
	if (m == 0) return NULL;
	/*����һ���յ�˳�����*/
	PseqQueue palist = (PseqQueue)malloc(sizeof(struct seqQueue));
	if (palist != NULL) {
		palist->q = (DataType*)malloc(sizeof(DataType) * m);
		if (palist->q) {
			/*�ܴ�ŵ����Ԫ�ظ���Ϊ m*/
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
	/*�ж�˳�򣨻��Σ������Ƿ�Ϊ�գ���Ϊ�գ�����ֵΪ1*/
	if (Q == NULL) return -1;
	/*�����в����ڣ��򷵻�-1*/
	if (Q->front == Q->rear) return 1;
	else return 0;
}

int isFullQueue_seq(PseqQueue Q) {
	/*�жϻ��ζ����Ƿ�������������������ֵΪ1*/
	if ((Q->rear + 1) % (Q->MAXINUM) == Q->front) return 1;
	return 0;
}

int enQueue_seq(PseqQueue Q, DataType x) {
	//�ڻ��ζ����в�������Ԫ��x�������벻�ɹ�������0������ɹ�����ֵΪ1
	int q = isFullQueue_seq(Q);
	if (!q) {
		Q->q[Q->rear] = x;
		Q->rear = (Q->rear + 1) % (Q->MAXINUM);
		return 1;
	} else return 0;
}

DataType delQueue_seq(PseqQueue Q) {
	//���Ӳ�����ɾ��Ԫ�أ�������Ϊ�գ��򷵻�-1
	if (Q->front == Q->rear) return -1;
	else {
		int m = Q->q[Q->front];
		Q->front = (Q->front + 1) % (Q->MAXINUM);
		return m;
	}
}

DataType front_seq(PseqQueue Q) {
	// ȡ����Ԫ�ط��أ�������Ϊ�գ��򷵻�-1
	if (Q->front == Q->rear) return -1;
	else return Q->q[Q->front];
}

//����˳����У��ͷŶ�����ռ�洢�ռ�
int destroyQueue_seq(PseqQueue Q) {
	//����ֵΪ���ٵ�ջ����������Ԫ�صĸ������������ٵ����Ա����ڣ��򷵻�0
	if (Q == NULL) return 0;
	else {
		int num = Q->front + 1;
		Q->MAXINUM = 0;
		free(Q->q);
		return num;
	}
}
