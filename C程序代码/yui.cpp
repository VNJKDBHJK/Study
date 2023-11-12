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

	PNODE pn, pre, q ;//pnΪ����Ľڵ�,preΪͷ�ڵ�����ӽڵ�,qΪpre�ڵ�����ӽڵ�
	int y = 1;//ָ��
	float x = 1; //ϵ��

	//����ͷָ��
	PNODE head = (PNODE)malloc(sizeof(Node));
	head->exp = -1;//ͷָ��ĵڶ�����Ϊ-1
	head->next = NULL;

	//ѭ������ֱ������ 0,0Ϊֹ
	for (; x != 0 || y != 0;)	{

		//����pn�ڵ�
		pn = (PNODE)malloc(sizeof(Node));
		printf("coef:\n");
		scanf("%f", &x); //�������ϵ��
		printf("exp:\n");
		scanf("%d", &y); //�������ָ��
		pn->coef = x;
		pn->exp = y;
		pn->next = NULL;

		// ��pn�ڵ���뵽����λ��
		if (head->next != NULL) {//û������ head->next = NULL;ʱ����д,��ֹ�Ҳ���head->next
			pre = head->next;
			if (head->next->next != NULL) {//�� head->next->next�� head->next�ֿ�, �� head->nextʱ��һ����head->next->next,����Ҳ���head->next->next��ʹ�����ֹ
				q = head->next->next;

				while (q && q->exp < pn->exp) {//q��pre����ָ������,q��pre����,ͨ���Ƚ�q->exp ��pn->exp ʹ pn->exp < q->exp ʹ pn->exp > pre->exp,��pn�ڵ�λ��q��pre�ڵ�֮��
					if (pre->exp > pn->exp) {//�ж�pre->exp >pn->exp �������,ֻ��ͷָ�����ŵĽڵ��exp > pn��ָ��ڵ��expʱ�Ż����
						q = pre;
						pre = head;
					} else {//q->exp < pn->expʱ
						pre = q;
						q = q->next;
					}
				}
			}

			if (pre->exp < pn->exp) {//��ֹ���ֵ�һ������ڵ��exp > pn�ڵ��exp�������
				pre->next = pn;//��pre����pn
				pn = pn->next;

			} else { // pre->exp > pn->exp
				pn->next = pre;
				head->next = pn;
				pn = pre;

			}
			continue;
		}

		head->next = pn;//ֻ�е�һ��,û��pre��qʱ��head����
		pn = pn->next;

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
	//���ڶ�������ʽ��ϵ���Լ�ָ�����ڵ�һ������ʽ�Ľṹ��������
	PNODE L1 = (PNODE)malloc(sizeof(Node));
	PNODE p1 = polyAddLeft->next;
	PNODE q1 = polyAddRight->next;
	PNODE pre = L1, temp1;

	float sum;
	while (p1 != NULL && q1 != NULL) { //������������Ϊ��
		//������ʱ�ڵ�temp1
		temp1 = (PNODE)malloc(sizeof(Node));

		//�Ƚ�����1������2��ǰ�ڵ��ָ����С������1Ҳ�Ǵ�Ž���ĵط�
		if (p1->exp < q1->exp) {
			temp1->coef = p1->coef;
			temp1->exp = p1->exp;

			p1 = p1->next;
		} else if (p1->exp == q1->exp) { //��������1������2��ָ����ȣ���Ҫϵ�����

			sum = p1->coef + q1->coef;
			if (sum) {
				temp1->coef = sum;
				temp1->exp = p1->exp;

			}
			p1 = p1->next;
			q1 = q1->next;
		} else
			//�������2�ĵ�ǰ�ڵ�ָ��С��
			//��ôҪ������2�ĵ�ǰ�ڵ���뵽��������У���������1��
		{
			//�൱�ڰѽ����뵽����1�У�
			temp1->coef = q1->coef;
			temp1->exp = q1->exp;

			q1 = q1->next;
		}

		//preһֱָ��β�ڵ�
		pre->next = temp1;
		pre = temp1;
	}

	if (q1) {
		temp1 = (PNODE)malloc(sizeof(PNODE));
		temp1->exp = q1->exp;
		temp1->coef = q1->coef;

		pre->next = temp1;
		pre = temp1;

		q1 = q1->next;
	}
	

	return L1;

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
	p = poly->next;
	p = p->next;

	for (; p->next != NULL; p = p->next) {
		if (p->coef) {
			printf("%.fx^%d", p->coef, p->exp);
		}
		if (p->next != NULL && p->next->coef>0) {
			printf("+");
		}
	}
	return;

	/**********  End **********/
}


int main(void) {
	printf("2200350204�����.��һ��\n");
	PNODE  polyAddLeft, polyAddRight, polyAddResult ;

	polyAddLeft = createPoly();
	printf("print another\n");
	polyAddRight = createPoly();
	
	polyAddResult = addPoly(polyAddLeft, polyAddRight);
	printPoly(polyAddResult);
}
