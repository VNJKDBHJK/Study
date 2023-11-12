#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Node {
	int num;
	DataType *element;
}*node;

node createList() {
	node mylist = (node)malloc(sizeof(struct Node));
	if (mylist != NULL) {
		mylist->element = (DataType*)malloc(sizeof(DataType));
		if (mylist->element) {
			mylist->num = 0;
			return mylist;
		}
		free(mylist);
	}
	return NULL;
}

void insert(node L, int m, int x) {
	L->element[m] = x;
	L->num = L->num + 1;
}

int find(node L, int x) {
	return (L->element[x]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	node head = createList();
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		insert(head, i, x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		int k = find(head, x);
		printf("%d", k - 1);
	}
}
