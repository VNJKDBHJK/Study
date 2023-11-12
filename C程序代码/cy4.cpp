#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define max 10000
/*
哈夫曼树结构
*/
struct node { //哈夫曼树结点的结构
	int ww;
	int parent, llink, rlink;
	char codes[10];
};

struct tree { //哈夫曼树结构
	int m;
	int root;
	struct node *ht;
};

typedef struct tree *Ptree;

/*创建哈夫曼树*/

Ptree creathuffman(int m, int* w) { //创建哈弗曼树
	int num = 2 * m - 1;
	int i, j, x1, x2, m1, m2;
	Ptree huf = (Ptree)malloc(sizeof(struct tree));
	huf->ht = (struct node*)malloc(sizeof(struct node) * num);//分配空间

	for (i = 0; i < num; i++) {
		huf->ht[i].llink = huf->ht[i].parent = huf->ht[i].rlink = -1;

		if (i < m) {
			huf->ht[i].ww = w[i];
		} else {
			huf->ht[i].ww = -1;
		}
	}//初始化哈弗曼树
	
	for (i = 0; i < m - 1; i++) {
		m1 = m2 = max;
		x1 = x2 = -1;
		for (j = 0; j < m + i; j++) {//寻找两个最小权的无父节点的结点
			if (huf->ht[j].ww < m1 && huf->ht[j].parent == -1) {//x1存放最小的下标
				m2 = m1;
				x2 = x1;
				m1 = huf->ht[j].ww;
				x1 = j;
			} else if (huf->ht[j].ww < m2 && huf->ht[j].parent == -1) { //x1存放次小的下标
				m2 = huf->ht[j].ww;
				x2 = j;
			}
		}
		huf->ht[x1].parent = huf->ht[x2].parent = m + i;
		huf->ht[m + i].ww = m1 + m2;
		huf->ht[m + i].llink = x1;
		huf->ht[m + i].rlink = x2;//默认右大左小
	}
	huf->root = 2 * m - 2;
	return huf;
}

void huffmancodes(Ptree huf, int n) {
	char* temp;
	temp = new char[n];
	temp[n - 1] = '\0';
	int start, pos, parent;
	for (int i = 0; i < n; i++) {
		start = n - 1;
		pos = i;
		parent = huf->ht[i].parent;
		while (parent != -1) {
			if (huf->ht[parent].llink == pos) {
				temp[--start] = '0';
			} else {
				temp[--start] = '1';
			}
			pos = parent;
			parent = huf->ht[parent].parent;
		}
		strcpy(&huf->ht[i].codes[0], &temp[start]);
	}
	delete temp;

}

void inOrderhuffman(Ptree huf) {
	int i = huf->root;
	if (huf->ht[i].llink == -1) {
		cout << huf->ht[i].ww << " " << huf->ht[i].codes << endl;
		return;
	}

	huf->root = huf->ht[i].llink;
	inOrderhuffman(huf);

	huf->root = huf->ht[i].rlink;
	inOrderhuffman(huf);

}

int main() {

	int m, ww;
	cin >> m;//输入叶子结点个数
	Ptree huf;
	int w[100];//存放权值
	for (int i = 0; i < m; i++) {
		cin >> ww;
		w[i] = ww;
	}
	huf = creathuffman(m, w);
	huffmancodes(huf, m);
	inOrderhuffman(huf);
}
