#include <stdio.h>
#include <stdlib.h>

/*�˴���˳�����Ա����ݽṹ����*/
typedef int DataType;
struct seqList {
	//��3�����ݳ�Ա
	int MAXNUM;//���ڼ�¼˳�����Ա����ܴ�ŵ����Ԫ�ظ����� ���� MAXNUM
	int curNum;//���ڴ��˳�����Ա�������Ԫ�صĸ���  ����  curNum
	DataType *element;//���ڴ��˳�����Ա�����Ԫ�ص������ռ����ʼ��ַ
};

typedef struct seqList *PseqList;
//��һ��
PseqList createNullList_seq(int m) {
	//�˴���д���룬����һ���յ�˳�����Ա��ܴ�ŵ����Ԫ�ظ���Ϊ m
//��m=0���򷵻�NULL
	if (m == 0) return NULL;
	PseqList myList = (PseqList)malloc(sizeof(seqList));
	if (myList != NULL) {
		myList->element = (DataType*)malloc(m * sizeof(DataType));
		if (myList->element) {
			myList->MAXNUM = m;
			myList->curNum = 0;
			return myList;
		}
		free(myList);
	}
	printf("Out of sapce!!\n");
	return NULL;
}

//�ڶ���
int isFullList_seq(PseqList L) {
	//�ж�˳�����Ա��Ƿ�������������������ֵΪ1�����򷵻�ֵΪ0
	return L->curNum >= L->MAXNUM ? 1 : 0;
}


int insertP_seq(PseqList L, int p, int x) {
	// �����Ա�L���±�Ϊp��λ�ò�������Ԫ��x�����±�p�Ƿ������Ա������޷��������ݣ�����0������ɹ�����ֵΪ1
	//������Ա����ˣ� ������"list is full"����ʾ
	//�������λ�÷Ƿ����������ʾ"position is illegel"
	int i;
	if (L->curNum == L->MAXNUM) {
		printf("list is full");
		return 0;
	}
	if (p < 0 || p > L->curNum) {
		printf("position is illegel");
		return 0;
	}
	for (i = L->curNum; i >= p; i--) {
		L->element[i + 1] = L->element[i];
	}
	L->element[p] = x;
	L->curNum = L->curNum + 1;
	return 1;
}

int insertPre_seq(PseqList L, int p, int x) {
// �����Ա�L���±�Ϊp��λ�õ�ǰ���������Ԫ��x�����±�p�Ƿ������Ա������޷��������ݣ�����0������ɹ�����ֵΪ1
//��ʾ��ֱ�ӵ���insertP����ʵ�ּ���
	insertP_seq(L, p - 1, x);
}

int insertPost_seq(PseqList L, int p, int x) {
// �����Ա�L���±�Ϊp��λ�õĺ����������Ԫ��x�����±�p�Ƿ������Ա������޷��������ݣ�����0������ɹ�����ֵΪ1
//��ʾ��ֱ�ӵ���insertP����ʵ�ּ���
	insertP_seq(L, p + 1, x);
}

void printList_seq(PseqList L) {
	//���������Ա��Ԫ�أ����ڵ���������Ԫ��֮����һ���ո�Ϊ�ָ�������
	for (int i = 0; i < L->curNum; i++) {
		printf("%d ", L->curNum + i);
	}
}

//������
int destroyList_seq(PseqList L) {
	//����ֵΪ���ٵ����Ա�����������Ԫ�صĸ������������ٵ����Ա����ڣ��򷵻�0
	int i = 0;
	if (L == NULL) return 0;
	else  for (i = 0; i < L->curNum; i++) {}
	return i;
}

//���Ĺ�
int locate_seq(PseqList L, int x) {
	//��˳���L�в��Ҹ���ֵx�״γ��ֵ�λ�ã��������ڸ���ֵ���򷵻�-1
	for (int i = 0; i < L->curNum; i++)
		if (L->element[i] == x) return i;
	return -1;
}

DataType locatePos_seq(PseqList L, int pos) {
	// ��˳���L�в���ָ��λ��pos��������Ԫ�أ���λ�÷Ƿ����򷵻ص�0������Ԫ��
	if (pos < 0 || pos >= L->curNum) return L->element[0];
	else return L->element[pos];
}

//�����
int deletePos_seq(PseqList L, int pos) {
	//��˳���L��ɾ�����±�pos��������Ԫ�أ���pos�Ƿ����򷵻�-1�����򷵻�1
	if (pos < 0 || pos > L->curNum - 1) return -1;
	for (int i = pos; i < L->curNum - 1; i++)
		L->element[i] = L->element[i + 1];
	L->curNum = L->curNum - 1;
	return 1;
}

int delete_seq(PseqList L, int x) {
	//��˳���L��ɾ�������xֵ��ͬ������Ԫ�أ�����ɾ������Ԫ�صĸ���
	//����ʹ��֮ǰ����ɵĲ���
	int i, j;
	for (i = 0, j = 0; i < L->curNum; i++) {
		if (L->element[i] != x) {

			L->element[j] = L->element[i];
			j++;
		}
	}
	L->curNum = j;
	return i - j - 1;
}


//������
void replace_seq(PseqList L, int x, int y) {
	//��˳���L��ֵΪx������Ԫ���滻Ϊy
	for (int i = 0; i < L->curNum - 1; i++) {
		if (L->element[i] == x) L->element[i] = y;
	}
}

void delDuplicate_seq(PseqList L) {
	//�Ƴ����Ա��е������ظ�Ԫ�أ���Ҫʹ�ö��������ռ䣬������ԭ���޸��������� ����ʹ�� O(1) ����ռ�����������
	//ʹ�ó���ɾ�����ɣ����޸Ĳ�������
	for (int i = 0, k = 1; i < L->curNum - 1; k++) {
		if (L->element[i] == L->element[k]) {
			int j;
			for (j = k; j < L->curNum - 1; j++) {
				if (L->element[j] != L->element[i]) {
					L->element[j] = L->element[i];
					j++;
				}
			}
			L->curNum=j;
		}
		if(k==L->curNum-1){
			i++;
			k=i+1;
		}
	}
}






