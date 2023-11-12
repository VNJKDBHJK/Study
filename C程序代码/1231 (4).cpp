#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DataType;


//队列数据元素结构
typedef struct node {
	DataType info;
	struct node *next;
} QueueData;
//入栈 

typedef struct queueRecord {
	QueueData  *front, *rear ;
} LINKQUEUE;

typedef struct queueRecord *PLinkQueue;
//入队 

PLinkQueue createEmptyQueue_link( ) {
	//创建一个空队列，实质：生成一个LINKQUEUE类型的结点，并给front 和 rear 成员赋值
	//请在此处填写代码，完成相应功能
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
	//判定队列是否为空，实质： 看队列的front指针是否为空，若为空，则队列为空

	//请在此处填写代码，完成相应功能
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
	//将数据元素x插入队尾。实质：生成一个struct node类型的结点，并给相应成员赋值后插入队尾
	//请在此处填写代码，完成相应功能
	/*-------begin----------*/
	QueueData *s = (QueueData*)malloc(sizeof(QueueData));
	s->info = x;
	queue->rear->next = s;
	queue->rear = s;
	/*-------end----------*/
}

DataType deQueue_link(PLinkQueue Q) {
	//出队，实质： 取出Q队列的队首结点，返回该结点的数据元素，并将该结点使用enQueue_link(QueueData *p,PLinkQueue Q)插入队尾
	//本函数为针对本实验特殊设计，可实现秘钥的循环使用
	//请在此处填写代码，完成相应功能
	/*-------begin----------*/
	DataType x = Q->rear->info;
	QueueData *p;
	p=Q->front;
	Q->front=Q->front->next;
	
	enQueue_link(x, Q);
	return x;
	/*-------end----------*/

}
//下面放自己在有关栈的实验中写过的栈的代码，或者如果会用stl中的stack也可以用
//注意需要根据具体情况做必要修改
/*-------begin----------*/



/*-------end----------*/


/*
函数功能：输入字符串，使用栈和队列，判断该字符串是否是回文，是回文则返回1，否则返回0
输入参数： src 放的是要判断是否是回文的字符串
返回值：1：回文；0：不是回文
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
//请自行补充完整主函数，调用函数ishuiwen进行判断。

	/*-------begin----------*/





	/*-------end----------*/
	return 0;
}

