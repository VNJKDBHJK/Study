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
  函数功能：生成多项式
  函数名：createPoly
  函数参数：无
  返回值：指向多项式的头指针
*/

PNODE createPoly(void) {
	//在此处填写代码，能实现创建一个多项式并返回多项式头指针的函数
	//注意：头指针不存放多项式的项。

	/**********  Begin **********/

	PNODE pn, pre, q ;//pn为输入的节点,pre为头节点的连接节点,q为pre节点的连接节点
	int y = 1;//指数
	float x = 1; //系数

	//构建头指针
	PNODE head = (PNODE)malloc(sizeof(Node));
	head->exp = -1;//头指针的第二个域为-1
	head->next = NULL;

	//循环输入直到输入 0,0为止
	for (; x != 0 || y != 0;)	{

		//创建pn节点
		pn = (PNODE)malloc(sizeof(Node));
		printf("coef:\n");
		scanf("%f", &x); //输入项的系数
		printf("exp:\n");
		scanf("%d", &y); //输入项的指数
		pn->coef = x;
		pn->exp = y;
		pn->next = NULL;

		// 将pn节点插入到合适位置
		if (head->next != NULL) {//没有声明 head->next = NULL;时必须写,防止找不到head->next
			pre = head->next;
			if (head->next->next != NULL) {//将 head->next->next与 head->next分开, 有 head->next时不一定有head->next->next,如果找不到head->next->next会使程序截止
				q = head->next->next;

				while (q && q->exp < pn->exp) {//q和pre两个指针相邻,q在pre后面,通过比较q->exp 和pn->exp 使 pn->exp < q->exp 使 pn->exp > pre->exp,即pn节点位于q与pre节点之间
					if (pre->exp > pn->exp) {//判断pre->exp >pn->exp 这种情况,只有头指针连着的节点的exp > pn所指向节点的exp时才会出现
						q = pre;
						pre = head;
					} else {//q->exp < pn->exp时
						pre = q;
						q = q->next;
					}
				}
			}

			if (pre->exp < pn->exp) {//防止出现第一次输入节点的exp > pn节点的exp这种情况
				pre->next = pn;//用pre连接pn
				pn = pn->next;

			} else { // pre->exp > pn->exp
				pn->next = pre;
				head->next = pn;
				pn = pre;

			}
			continue;
		}

		head->next = pn;//只有第一次,没有pre和q时用head相连
		pn = pn->next;

	}

	return head;
	/**********  End  **********/
}

/*
   函数功能：进行多项式相加
   函数名：addPoly
   函数参数：polyAddLeft ：加法左边多项式头指针, polyAddRight：加法右边多项式头指针
   返回值：指向结果多项式的头指针
*/

PNODE addPoly(PNODE polyAddLeft, PNODE polyAddRight) {
	//在此处填写代码，能实现创两个多项式相加并返回结果多项式头指针的函数
	/**********  Begin **********/
	//将第二个多项式的系数以及指数放在第一个多项式的结构体数组中
	PNODE L1 = (PNODE)malloc(sizeof(Node));
	PNODE p1 = polyAddLeft->next;
	PNODE q1 = polyAddRight->next;
	PNODE pre = L1, temp1;

	float sum;
	while (p1 != NULL && q1 != NULL) { //当两个链表都不为空
		//创建临时节点temp1
		temp1 = (PNODE)malloc(sizeof(Node));

		//比较链表1跟链表2当前节点的指数大小，链表1也是存放结果的地方
		if (p1->exp < q1->exp) {
			temp1->coef = p1->coef;
			temp1->exp = p1->exp;

			p1 = p1->next;
		} else if (p1->exp == q1->exp) { //假如链表1和链表2的指数相等，就要系数相加

			sum = p1->coef + q1->coef;
			if (sum) {
				temp1->coef = sum;
				temp1->exp = p1->exp;

			}
			p1 = p1->next;
			q1 = q1->next;
		} else
			//如果链表2的当前节点指数小，
			//那么要把链表2的当前节点加入到结果链表中（即是链表1）
		{
			//相当于把结点插入到链表1中，
			temp1->coef = q1->coef;
			temp1->exp = q1->exp;

			q1 = q1->next;
		}

		//pre一直指向尾节点
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
   函数功能：输出多项式
   函数名：printPoly
   函数参数：待输出多项式的头指针poly
   返回值：无
*/


void printPoly(PNODE poly) {
	//在此处填写代码，能实现按格式输出多项式的功能，输出格式样例见说明
	/**********  Begin **********/
	//输出多项式的功能
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
	printf("2200350204李禹佳.第一题\n");
	PNODE  polyAddLeft, polyAddRight, polyAddResult ;

	polyAddLeft = createPoly();
	printf("print another\n");
	polyAddRight = createPoly();
	
	polyAddResult = addPoly(polyAddLeft, polyAddRight);
	printPoly(polyAddResult);
}
