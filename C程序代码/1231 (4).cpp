#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DataType;


//��������Ԫ�ؽṹ
typedef struct node {
	DataType info;
	struct node *next;
} QueueData;
//��ջ 

typedef struct queueRecord {
	QueueData  *front, *rear ;
} LINKQUEUE;

typedef struct queueRecord *PLinkQueue;
//��� 

PLinkQueue createEmptyQueue_link( ) {
	//����һ���ն��У�ʵ�ʣ�����һ��LINKQUEUE���͵Ľ�㣬����front �� rear ��Ա��ֵ
	//���ڴ˴���д���룬�����Ӧ����
	/*-------begin----------*/
	PLinkQueue link;
	link = (PLinkQueue)malloc(sizeof(LINKQUEUE));
	if (link == NULL) return NULL;
	QueueData *s = (QueueData*)malloc(sizeof(QueueData));
	if (s == NULL) return NULL;
	s->next = NULL;
	link->front = link->rear = s;
	return link;
	/*-------end----------*/

}

int isEmptyQueue_link(PLinkQueue  queue) {
	//�ж������Ƿ�Ϊ�գ�ʵ�ʣ� �����е�frontָ���Ƿ�Ϊ�գ���Ϊ�գ������Ϊ��

	//���ڴ˴���д���룬�����Ӧ����
	/*-------begin----------*/
	if (queue->front == NULL) return 0;
	return 1;
	/*-------end----------*/
}

//int main() {
//	PLinkQueue link = createEmptyQueue_link();
//	printf("%d", isEmptyQueue_link(link));
//}


void enQueue_link(DataType x, PLinkQueue queue) {
	//������Ԫ��x�����β��ʵ�ʣ�����һ��struct node���͵Ľ�㣬������Ӧ��Ա��ֵ������β
	//���ڴ˴���д���룬�����Ӧ����
	/*-------begin----------*/
	QueueData *s = (QueueData*)malloc(sizeof(QueueData));
	s->info = x;
	queue->rear->next = s;
	queue->rear = s;
	/*-------end----------*/
}

DataType deQueue_link(PLinkQueue Q) {
	//���ӣ�ʵ�ʣ� ȡ��Q���еĶ��׽�㣬���ظý�������Ԫ�أ������ý��ʹ��enQueue_link(QueueData *p,PLinkQueue Q)�����β
	//������Ϊ��Ա�ʵ��������ƣ���ʵ����Կ��ѭ��ʹ��
	//���ڴ˴���д���룬�����Ӧ����
	/*-------begin----------*/
	DataType x = Q->rear->info;
	QueueData *p;
	p=Q->front;
	Q->front=Q->front->next;
	
	enQueue_link(x, Q);
	return x;
	/*-------end----------*/

}
//������Լ����й�ջ��ʵ����д����ջ�Ĵ��룬�����������stl�е�stackҲ������
//ע����Ҫ���ݾ����������Ҫ�޸�
/*-------begin----------*/



/*-------end----------*/


/*
�������ܣ������ַ�����ʹ��ջ�Ͷ��У��жϸ��ַ����Ƿ��ǻ��ģ��ǻ����򷵻�1�����򷵻�0
��������� src �ŵ���Ҫ�ж��Ƿ��ǻ��ĵ��ַ���
����ֵ��1�����ģ�0�����ǻ���
*/
int ishuiwen(char src[]) {
	/*-------begin----------*/
	PLinkQueue link=createEmptyQueue_link();
	for(int i=0;src[i]!=0;i++){
		enQueue_link(src[i],link);
	}
	for(;;){
		
	}
	/*-------end----------*/

}

int main(void) {
//�����в������������������ú���ishuiwen�����жϡ�

	/*-------begin----------*/





	/*-------end----------*/
	return 0;
}

