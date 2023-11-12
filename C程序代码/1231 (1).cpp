#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/*�˴���˳��ջ���ݽṹ����*/
typedef int DataType;
struct seqStack {
	//��3�����ݳ�Ա
	int MAXNUM;//���ڼ�¼˳��ջ���ܴ�ŵ����Ԫ�ظ����� ���� MAXNUM
	int top;//���ڴ��˳��ջ��ջ��λ�ã���ʼ��Ϊ0��-1 ����  ����  curNum
	DataType *element;//���ڴ��˳��ջ����Ԫ�ص������ռ����ʼ��ַ
};

typedef seqStack *PseqStack;
//��һ��
PseqStack createNullStack_seq(int m) {
	//�˴���д���룬����һ���յ�˳��ջ���ܴ�ŵ����Ԫ�ظ���Ϊ m,ջ��top����Ϊ0
//��m=0���򷵻�NULL
	if (m == 0) return NULL;
	PseqStack palist = (PseqStack)malloc(sizeof(struct seqStack));
	if (palist != NULL) {
		palist->element = (DataType*)malloc(sizeof(DataType) * m);
		if (palist->element) {
			palist->MAXNUM = m;
			palist->top = 0;
			return palist;
		} else free(palist);
	}
	return NULL;
}

//�ڶ���
int isNullStack_seq(PseqStack L) {
	//�ж�˳��ջ�Ƿ�Ϊ�գ���Ϊ�գ�����ֵΪ1�����򷵻�ֵΪ0,��ջ�����ڣ��򷵻�-1
	if (L == NULL) return -1;
	else {
		if (L->top == 0) return 1;
		else return 0;
	}
}


//������
int isFullStack_seq(PseqStack L) {
	//�ж�˳��ջ�Ƿ�������������������ֵΪ1�����򷵻�ֵΪ0
	if (L->top == L->MAXNUM) return 1;
	return 0;
}


//���Ĺ�
int push_seq(PseqStack L, DataType x) {
	//��˳��ջ�в�������Ԫ��x�������벻�ɹ�������0������ɹ�����ֵΪ1
	if (isFullStack_seq(L)) return 0;
	L->top = L->top + 1;
	L->element[L->top] = x;
	return 1;
}



//�����
DataType pop_seq(PseqStack L) {
	//��ջ������ɾ��Ԫ�أ���ջΪ�գ��򷵻�-1
	if (isNullStack_seq(L) == 1) return -1;
	int m = L->element[L->top];
	L->top = L->top - 1;
	return m;
}

//������
DataType top_seq(PseqStack L) {
	// ȡջ��Ԫ�ط��أ���ջΪ�գ��򷵻�-1
	if (isNullStack_seq(L)) return -1;
	return (L->element[L->top]);
}

//����˳��ջ���ͷ�ջ��ռ�洢�ռ�
int destroystack_seq(PseqStack L) {
	//����ֵΪ���ٵ�ջ����������Ԫ�صĸ������������ٵ����Ա����ڣ��򷵻�0
	if (L) return 0;
	int m = L->top;
	free(L->element);
	return m;
}


//���߹�
//ʹ����ʵ�ֵ�ջ������ʵ������ת��

void print(PseqStack L) {
//�������ջL�е�����Ԫ�ز������������ݼ䲻��Ҫ�κμ������
	while (!isNullStack_seq(L))
		printf("%d", pop_seq(L));

}

void convert(int data, int k) {
//����ջʵ�ֽ�dataת��Ϊk���ƣ�k������2��8��16. �ڱ�������ʵ��ת��������print�������ת����Ľ��
//ʮ������ʱ��� A ,B ,C, D,E,F ʹ�ô�д��ĸ
	int m = data;
	PseqStack head = createNullStack_seq(10);
	while (m) {
		push_seq(head, m % k);
		m /= k;
	}
	if (k == 2 || k == 8) print(head);
	else {
		while (!isNullStack_seq(head)) {
			if (head->element[head->top] >= 10) printf("%c", head->element[head->top] + 55);
			else printf("%d", head->element[head->top]);
			pop_seq(head);
		}
	}

}
