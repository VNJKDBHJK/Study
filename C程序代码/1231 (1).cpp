#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/*此处是顺序栈数据结构定义*/
typedef int DataType;
struct seqStack {
	//有3个数据成员
	int MAXNUM;//用于记录顺序栈中能存放的最大元素个数的 整型 MAXNUM
	int top;//用于存放顺序栈的栈顶位置，初始化为0或-1 均可  整型  curNum
	DataType *element;//用于存放顺序栈数据元素的连续空间的起始地址
};

typedef seqStack *PseqStack;
//第一关
PseqStack createNullStack_seq(int m) {
	//此处填写代码，创建一个空的顺序栈，能存放的最大元素个数为 m,栈顶top设置为0
//若m=0，则返回NULL
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

//第二关
int isNullStack_seq(PseqStack L) {
	//判断顺序栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
	if (L == NULL) return -1;
	else {
		if (L->top == 0) return 1;
		else return 0;
	}
}


//第三关
int isFullStack_seq(PseqStack L) {
	//判断顺序栈是否已满，若已满，返回值为1，否则返回值为0
	if (L->top == L->MAXNUM) return 1;
	return 0;
}


//第四关
int push_seq(PseqStack L, DataType x) {
	//在顺序栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
	if (isFullStack_seq(L)) return 0;
	L->top = L->top + 1;
	L->element[L->top] = x;
	return 1;
}



//第五关
DataType pop_seq(PseqStack L) {
	//弹栈并返回删除元素，若栈为空，则返回-1
	if (isNullStack_seq(L) == 1) return -1;
	int m = L->element[L->top];
	L->top = L->top - 1;
	return m;
}

//第六关
DataType top_seq(PseqStack L) {
	// 取栈顶元素返回，若栈为空，则返回-1
	if (isNullStack_seq(L)) return -1;
	return (L->element[L->top]);
}

//销毁顺序栈，释放栈所占存储空间
int destroystack_seq(PseqStack L) {
	//返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
	if (L) return 0;
	int m = L->top;
	free(L->element);
	return m;
}


//第七关
//使用已实现的栈操作，实现数制转换

void print(PseqStack L) {
//逐个弹出栈L中的数据元素并输出，输出数据间不需要任何间隔符号
	while (!isNullStack_seq(L))
		printf("%d", pop_seq(L));

}

void convert(int data, int k) {
//利用栈实现将data转换为k进制，k可能是2，8，16. 在本函数内实现转换并调用print函数输出转换后的结果
//十六进制时输出 A ,B ,C, D,E,F 使用大写字母
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
