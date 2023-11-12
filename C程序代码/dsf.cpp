#define _LINKSET_H_
#include <iostream>
#include<stdlib.h>
using namespace std;
typedef int DataType;

struct  node {
	DataType  element;
	struct node  *next;
};
typedef struct node * SET;
void insert(DataType datax, SET set);

/*
  �������� InitSet
  �������ܣ����ݲ���num����ʼ������
  ��������������Ԫ�صĸ���
  ����ֵ������ͷָ��
*/
SET InitSet(int num) {

	SET p;
	p = new struct  node  ;
	p->next = NULL;
	p->element = num;
	int temp;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		insert(temp, p); //����insert���������������ݲ��뼯��
	}
	return p;
}

/*
  �������� find
  �������ܣ��ڼ����в���ֵΪdatax�ĳ�Ա
  ����������datax:�����ҵ�ֵ �� set�����ϵ�ͷ���
  ����ֵ���ҵ�ֵΪdatax�ĳ�Ա����1�����򷵻�0
*/
int find(DataType datax, SET  set) {
	//���ڴ˴���д���룬��set�����в���ֵΪdatax�ĳ�Ա�����ҵ�����1�����򷵻�0
	/**********  Begin  **********/
	SET sset;
	sset = set->next;
	for (; sset != NULL;) {
		if (sset->element == datax)	return 1;
		sset = sset->next;
	}
	return 0;

	/**********   End   **********/
}

/*
  �������� insert
  �������ܣ��ڼ���set�в���ֵΪdatax�ĳ�Ա ������λ���ڱ�ͷ
  ����������datax:�������ֵ �� set�����ϵ�ͷ���
  ����ֵ����
*/
void insert(DataType datax, SET set) {
	//���ڴ˴���д���룬��datax���뼯��set�� ע���򼯺�Ԫ��������ģ�ֻ�轫�³�Ա�����ͷ
	/**********  Begin  **********/
	SET sset = (node*)malloc(sizeof(node));
	sset->element = datax;
	sset->next = set->next;
	set->next = sset;
	/**********   End   **********/
}

/*
  �������� copyList
  �������ܣ�������setA�������ɼ���setB
  ����������setA ��setB��ͷ���
  ����ֵ����
*/
void copySet(SET setA, SET setB) {
	//���ڴ˴���д���룬ʵ�ֽ�����setA�ĳ�Ա���Ƶ�����setB�Ĺ���
	/**********  Begin  **********/
	SET sset1, sset2 ;
	sset1 = setA, sset2 = setB;
	for (; sset1 != NULL;) {
		sset2 = sset1;
		sset1 = sset1->next;
	}
	/**********   End   **********/
}

/*
  �������� printSet
  �������ܣ�������ϵ�Ԫ�أ��Կո���ΪԪ��֮��ֽ��
  ����������set��ͷ���
  ����ֵ����
*/
void printSet(SET set) {
	//���ڴ˴���д���룬ʵ���������Ԫ�صĹ��ܣ�Ԫ��֮���Կո�Ϊ�ֽ��
	/**********  Begin  **********/
	SET sset;
	sset = set->next; //ע��ͷ�ڵ㲻��Ԫ��,�������ﲻ��ֱ�ӵ���set����set->next
	for (; sset != NULL;) { //ע��������sset������sset->next
		printf("%d ", sset->element);
		sset = sset->next;
	}
	/**********  End  **********/
}

/*
  �������� setUnion
  �������ܣ�����������setA �� setB�Ĳ���
  ����������setA��setB��ͷ���
  ����ֵ���������ϵ�ͷ���
*/
SET setUnion(SET setA, SET setB) {
	//���ڴ˴���д���룬��ֱ��ʹ�������Ѿ�ʵ�ֵĸ�����
	/**********  Begin  **********/
	SET sset1 = setA->next, sset2 = setB->next;

	SET head = (SET)malloc(sizeof(node));
	head->next = NULL;

	for (; sset1 != NULL;) {
		insert(sset1->element, head);
		sset1 = sset1->next;
	}

	for (; sset2 != NULL;) {
		if (find(sset2->element, setA) == 0) insert(sset2->element, head);
		sset2 = sset2->next;
	}

	return head;
	/**********  End  **********/
}

/*
  �������� setIntersect
  �������ܣ�����������setA �� setB�Ľ���
  ����������setA��setB��ͷ���
  ����ֵ���������ϵ�ͷ���
*/
SET setIntersect(SET setA, SET setB) {
	//���ڴ˴���д���룬��ֱ��ʹ�������Ѿ�ʵ�ֵĸ�����
	/**********  Begin  **********/
	SET sset1 = setA->next;
	SET head = (SET)malloc(sizeof(node));
	head->next = NULL;

	for (; sset1 != NULL;) {
		if (find(sset1->element, setB) == 1) insert(sset1->element, head);
		sset1 = sset1->next;
	}

	return head;
	/**********  End  **********/
}

/*
  �������� setExcept
  �������ܣ�����������setA �� setB�Ĳ�
  ����������setA��setB��ͷ���
  ����ֵ��������ϵ�ͷ���
*/
SET setExcept(SET setA, SET setB) {
	//���ڴ˴���д���룬��ֱ��ʹ�������Ѿ�ʵ�ֵĸ�����
	/**********  Begin  **********/
	SET sset1 = setA->next;

	SET head = (SET)malloc(sizeof(node));
	head->next = NULL;

	for (; sset1 != NULL;) {
		if (find(sset1->element, setB) == 0) insert(sset1->element, head);
		sset1 = sset1->next;
	}

	return head;
	/**********  End  **********/
}

int main(void) {
	int count;
	cin >> count;
	SET setA = InitSet(count);
	cin >> count;
	SET setB = InitSet(count);

//	printf("%d",find(1,setA));

//    SET setc;
//    copySet(setA,setc);

	cout << "������";
	printSet(setUnion(setA, setB));
	cout << "\n������";
	printSet(setIntersect(setA, setB));
	cout << "\n���";
	printSet(setExcept(setA, setB));

}
