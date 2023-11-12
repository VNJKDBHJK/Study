#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
} Node;
Node* CreateLink() {
	Node *a1, *a2, *head;
	int n;
	scanf("%d", &n);
	a1 = a2 = (Node*)malloc(sizeof(Node));
	head = NULL;
	for (int i = 0; i < n; i++) {
		if (i == 0) head = a1;
		else a2->next = a1;
		a2 = a1;
		a1 = (Node*)malloc(sizeof(Node));
		scanf("%d", &a2->data);
	}
	a2->next = NULL;
	return head;
}
Node* ChangeLink(Node* s) {
	Node *p, *q;
	p = s->next;
	s->next = NULL;
	for (; p->next != NULL;) {
		q = p;
		p = p->next;
		q->next = s->next;
		s->next = q;
	}
	q = p;
	p = p->next;
	q->next = s->next;
	s->next = q;
	return s;
}
void ShowList(Node* s) {//输出链表
	Node *p;
	p = s;
	for (; p->next != NULL;) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}
int main() {
	Node *phead;
	phead = CreateLink();
	printf("链表逆置前的数据:\n");
	ShowList(phead);
	phead = ChangeLink(phead);
	printf("链表逆置后的数据:\n");
	ShowList(phead);
	return 0;
}
