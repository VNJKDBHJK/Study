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
	PNODE pn, pre, q, head;
	head = (PNODE)malloc(sizeof(Node));
	head->next->exp = -1;
	head->next->next = NULL;
	for (;;)	{
		pn = (PNODE)malloc(sizeof(Node));
		printf("coef:\n");
		scanf("%f", &pn->coef); //输入项的系数
		printf("exp:\n");
		scanf("%d", &pn->exp); //输入项的指数
		if (pn->exp < 0) break; //若输入项指数负数，结果输入
		pre = head->next;
		q = head->next->next;
		while (q && q->exp > pn->exp) { //插入项并保证多项式的各项为降幂排列
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
   函数功能：进行多项式相加
   函数名：addPoly
   函数参数：polyAddLeft ：加法左边多项式头指针, polyAddRight：加法右边多项式头指针
   返回值：指向结果多项式的头指针
*/

PNODE addPoly(PNODE polyAddLeft, PNODE polyAddRight) {
	//在此处填写代码，能实现创两个多项式相加并返回结果多项式头指针的函数
	/**********  Begin **********/
	PNODE p = polyAddLeft->next;
	PNODE q = polyAddRight->next;
	Node *pre = p;
	Node *u;

	float x;
	while (p != NULL && q != NULL) { //当两个链表都不为空
		//比较链表1跟链表2当前节点的指数大小，链表1也是存放结果的地方
		if (p->exp < q->exp) {
			pre = p;
			//p指向要比较的下一个结点。pre指向的是结果链表的最后一个结点。
			p = p->next;
		} else if (p->exp == q->exp) { //假如链表1和链表2的指数相等，就要系数相加
			x = p->coef + q->coef;
			if (x != 0) { //相加后的系数不为0，有必要保留一个结点就可以了
				p->coef = x;
				pre = p;
			} else
				//如果相加后，系数是0，不需要保留任何一个结点，
				//在这里删除链表1的结点，下面删除链表2的结点
			{
				pre->next = p->next; //保持链表1的连续性
				free(p);
			}
			p = pre->next; //p指向要比较的下一个结点
			//下面的代码是进行链表2结点的删除工作
			//因为指数相等，仅仅需要保留一个结点就可以了
			//而结果直接保存在链表1中，所以，删除链表2的结点。
			u = q;
			q = q->next;
			free(u);
		} else
			//如果链表2的当前节点指数小，
			//那么要把链表2的当前节点加入到结果链表中（即是链表1）
		{
			//相当于把结点插入到链表1中，
			//用u作为临时变量，保存链表2的下一个当前节点的位置。
			u = q->next;
			q->next = p;
			pre->next = q;
			pre = q;
			q = u;
		}

	}
	//如果链表2比链表1长，那么需要把链表2多余的部分加入结果链表中。
	//链表1比链表2长，则什么都不用做。
	if (q) {
		pre->next = q;
	}
	free(q);

	return u;

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
