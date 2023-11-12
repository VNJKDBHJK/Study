#include<stdio.h>
#include<stdlib.h>
struct tagNode {
	float coef;
	int exp;
	struct tagNode *next;
};

typedef struct tagNode Node;
typedef struct tagNode*  PNODE;

/*
  �������ܣ����ɶ���ʽ
  ��������createPoly
  ������������
  ����ֵ��ָ�����ʽ��ͷָ��
*/

PNODE createPoly(void) {
	//�ڴ˴���д���룬��ʵ�ִ���һ������ʽ�����ض���ʽͷָ��ĺ���
	//ע�⣺ͷָ�벻��Ŷ���ʽ���
	/**********  Begin **********/
	PNODE pn, pre, q, head;
	head = (PNODE)malloc(sizeof(Node));
	head->next->exp = -1;
	head->next->next = NULL;
	for (;;)	{
		pn = (PNODE)malloc(sizeof(Node));
		printf("coef:\n");
		scanf("%f", &pn->coef); //�������ϵ��
		printf("exp:\n");
		scanf("%d", &pn->exp); //�������ָ��
		if (pn->exp < 0) break; //��������ָ���������������
		pre = head->next;
		q = head->next->next;
		while (q && q->exp > pn->exp) { //�������֤����ʽ�ĸ���Ϊ��������
			pre = q;
			q = q->next;
		}
		pn->next = q;
		pre->next = pn;
	}
	return head;
	/**********  End  **********/
}

/*
   �������ܣ����ж���ʽ���
   ��������addPoly
   ����������polyAddLeft ���ӷ���߶���ʽͷָ��, polyAddRight���ӷ��ұ߶���ʽͷָ��
   ����ֵ��ָ��������ʽ��ͷָ��
*/

PNODE addPoly(PNODE polyAddLeft, PNODE polyAddRight) {
	//�ڴ˴���д���룬��ʵ�ִ���������ʽ��Ӳ����ؽ������ʽͷָ��ĺ���
	/**********  Begin **********/
	PNODE p = polyAddLeft->next;
	PNODE q = polyAddRight->next;
	Node *pre = p;
	Node *u;

	float x;
	while (p != NULL && q != NULL) { //������������Ϊ��
		//�Ƚ�����1������2��ǰ�ڵ��ָ����С������1Ҳ�Ǵ�Ž���ĵط�
		if (p->exp < q->exp) {
			pre = p;
			//pָ��Ҫ�Ƚϵ���һ����㡣preָ����ǽ����������һ����㡣
			p = p->next;
		} else if (p->exp == q->exp) { //��������1������2��ָ����ȣ���Ҫϵ�����
			x = p->coef + q->coef;
			if (x != 0) { //��Ӻ��ϵ����Ϊ0���б�Ҫ����һ�����Ϳ�����
				p->coef = x;
				pre = p;
			} else
				//�����Ӻ�ϵ����0������Ҫ�����κ�һ����㣬
				//������ɾ������1�Ľ�㣬����ɾ������2�Ľ��
			{
				pre->next = p->next; //��������1��������
				free(p);
			}
			p = pre->next; //pָ��Ҫ�Ƚϵ���һ�����
			//����Ĵ����ǽ�������2����ɾ������
			//��Ϊָ����ȣ�������Ҫ����һ�����Ϳ�����
			//�����ֱ�ӱ���������1�У����ԣ�ɾ������2�Ľ�㡣
			u = q;
			q = q->next;
			free(u);
		} else
			//�������2�ĵ�ǰ�ڵ�ָ��С��
			//��ôҪ������2�ĵ�ǰ�ڵ���뵽��������У���������1��
		{
			//�൱�ڰѽ����뵽����1�У�
			//��u��Ϊ��ʱ��������������2����һ����ǰ�ڵ��λ�á�
			u = q->next;
			q->next = p;
			pre->next = q;
			pre = q;
			q = u;
		}

	}
	//�������2������1������ô��Ҫ������2����Ĳ��ּ����������С�
	//����1������2������ʲô����������
	if (q) {
		pre->next = q;
	}
	free(q);

	return u;

	/**********  End **********/
}

/*
   �������ܣ��������ʽ
   ��������printPoly
   �������������������ʽ��ͷָ��poly
   ����ֵ����
*/

void printPoly(PNODE poly) {
	//�ڴ˴���д���룬��ʵ�ְ���ʽ�������ʽ�Ĺ��ܣ������ʽ������˵��
	/**********  Begin **********/
	//�������ʽ�Ĺ���
	PNODE p;
	p = (PNODE)malloc(sizeof(PNODE));
	for (p = poly->next; p != NULL; p = p->next) {
		if (p->coef != 0) {
			printf("%fx^%d", p->coef, p->exp);
		}
		if (p->next != NULL && p->next->coef > 0) {
			printf("+");
		}
	}
	return;

	/**********  End **********/
}


int main(void) {
	PNODE  polyAddLeft, polyAddRight, polyAddResult ;

	polyAddLeft = createPoly();

	polyAddRight = createPoly();

	polyAddResult = addPoly(polyAddLeft, polyAddRight);
	printPoly(polyAddResult);

}
