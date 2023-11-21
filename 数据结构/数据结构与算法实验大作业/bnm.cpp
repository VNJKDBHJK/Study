#define GRAPH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 6

int graph[N][N];
typedef struct DijMap {
	int record[N] = {0};
	int moon[N] = {0};
} DMap;

//����map,���붥�����
DMap* scanDijkastra(int n, int a) {
	int m;//�ߵĸ���
	char v[20];
	if (a == 1) {
		printf("enter the number of edges:\n");
		scanf("%d", &m);
		printf("Enter the weights of the starting point, end point, and the number of all sides:\n");
		for (int i = 0; i < m; i++) {
			int a, b, c; //���,�յ�,Ȩֵ
			scanf("%d%d%d", &a, &b, &c);
			graph[a][b] = c;
			graph[b][a] = c;
			graph[i][i] = 0;
			for (int j = 0; j < n; j++) {
				if (j != i && j != a && j != b) {
					graph[i][j] = 1000;
				}
			}
		}
		//����Ȩֵ����
	} else {
		FILE* fp = fopen("a3.txt", "r");
		if (fp == NULL) {
			perror("open file for reading");
			exit(0);
		}
		fgets(v, 20, fp);
		for (int o = 0; o < 20; o++) {
			v[o] -= 48;
		}
		m = v[0];
		for (int i = 0, j = 1; i < m; i++, j += 3) {
			int a, b, c; //���,�յ�,Ȩֵ
			a = v[j];
			b = v[j + 1];
			c = v[j + 2];
			graph[a][b] = c;
			graph[b][a] = c;
			graph[i][i] = 0;
			for (int j = 0; j < n; j++) {
				if (j != i && j != a && j != b) {
					graph[i][j] = 1000;
				}
			}
		}
	}

	DMap *map = (DMap *)malloc(sizeof(DMap));
	for (int i = 0; i < n; i++) {
		map->record[i] = graph[0][i];
		map->moon[i] = map->record[i];
	}
	//������ĵ�һ�и�ΪȨֵ�ĳ�ʼֵ

	return map;
}

//����map,������� ,���A����������·��
void printDijkastra(int n, DMap *map, int a) {
	char c = 'A';
	if (a == 1) {
		for (int i = 0; i < n; i++) {
			printf("A->%c:%d", c + i, map->moon[i]);
			if (i != n - 1) printf("\n");
		}
	} else {
		FILE *fp = fopen("a3-1.txt", "w");
		char a = 'A';
		char b = '-';
		char c = '>';
		char d = ':';
		char e = '\n';
		for (int i = 0; i < n; i++) {
			fputc(a, fp);
			fputc(b, fp);
			fputc(c, fp);
			fputc(a + i, fp);
			fputc(d, fp);
			if (map->moon[i] > 10) {
				for (int o = map->moon[i]; o > 0; o /= 10)
					fputc(map->moon[i] % 10 + 48, fp);
			} else {
				fputc(map->moon[i] + 48, fp);
			}
			if (i != n - 1) fputc(e, fp);
		}
	}
}

// Dijkastra�㷨���A����������·��
//���붥�������map
DMap* Dijkastra(int n, DMap *map) {
	int min = 0, minn = 0;
	for (int i = 0; i < n; i++) {
		if (map->record[i] != 0) {
			min = map->record[i];
			minn = i;
			break;
		}
	}
	//��record�����е�һ����0��ֵ��Ϊmin�ĳ�ʼֵ,minn���λ��

	for (int i = 1; i < n; i++)//
		if (map->record[i] != 0)
			if (min > map->record[i]) {
				min = map->record[i];
				minn = i;
			}
	map->record[minn] = 0;
	//�ҵ���Ϊ0��record��������С���Ǹ���,��record������Ǹ�ֵ��Ϊ0

	for (int i = 0; i < n; i++)
		if (map->record[i] != 0)
			if (map->moon[minn] + graph[minn][i] < map->moon[i])
				map->moon[i] = map->moon[minn] + graph[minn][i];
	//����Ȩֵ

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (map->record[i] != 0) {
			m = 1;
			break;
		}
	}
	if (m == 0) return map;
	//���moon���鶼Ϊ0,����

	Dijkastra(n, map);//�ݹ�
}

//�ڽӾ������ݽṹ
typedef struct {
	int vcount;     //������
	int type;       // 0 ����ͼ��1 ����ͼ
	char vexs[N];   // ������Ϣ
	int arcs[N][N]; //��ϵ����
	int mon[N][N];  //Ȩֵ
} GraphMatrix;

//�ڽӱ����ݽṹ
struct EdgeNode {
	int endvex;                //��Ӧ����ı߱��±�
	int weight;                //�ߵ�Ȩ
	struct EdgeNode *nextedge; //���ֶ�
};
typedef struct EdgeNode *EdgeList;

//�����
typedef struct {
	char vertex;       //��¼�������Ϣ
	int degree;        //���ڼ�¼�������ȣ�����������ʱ��ʹ��
	EdgeList edgelist; //ָ��߱��ָ��
} VexNode;

//�ڽӱ�
typedef struct {
	VexNode vexs[N]; // N������
	int type;        // 0����ͼ��1����ͼ
	int vcount;      //������
} GraphList;

//ͼ�ĳ�ʼ��
//�ڽӾ���洢
GraphMatrix *initGraphMatrix(int a) {
	GraphMatrix *map = (GraphMatrix *)malloc(sizeof(GraphMatrix));
	int n;
	char v[20];
	if (a == 1) {
		//����ͼ�����͡�ͼ�Ķ������ͱ���
		printf("enter the type of the graph (0->UndiGraph/1->DiGraph):\n");
		scanf("%d", &map->type);
		printf("enter the top point number of matrix(number<=6 is legal):\n");
		for (;;) {
			scanf("%d", &map->vcount);
			if (map->vcount <= 6) break;
			else printf("!!!illegal input!!!\n");
		}
		printf("enter the number of edges(number<=6 is legal):\n");
		for (;;) {
			scanf("%d", &n);
			if (n <= 6) break;
			else printf("!!!illegal input!!!\n");
		}
	} else {
		FILE* fp = fopen("a1.txt", "r");
		if (fp == NULL) {
			perror("open file for reading");
			exit(0);
		}
		fgets(v, 20, fp);
		for (int o = 0; o < 20; o++) {
			v[o] -= 48;
		}
		map->type = v[0];
		map->vcount = v[1];
		n = v[2];
	}

	for (int i = 0; i < map->vcount; i++)//�γ���map->vcountΪ�ߵ������ξ���,��ʼΪ0
		for (int j = 0; j < map->vcount; j++)
			map->arcs[i][j] = 0;

	int j, k;
	if (a == 1) {
		int i = 0;
		printf("print the number of the start point and the end point of all sides:\n");
		while (i < n) {
			scanf("%d%d", &j, &k);//��������ߵ�������ı��

			map->arcs[j][k] = 1;//����,���ſ�
			if (map->type == 0) {//���������ͼ
				map->arcs[k][j] = 1;//����,���ſ�
			}

			i++;
		}
	} else {
		for (int i = 0, m = 3; i < n; i++, m += 2) {
			j = v[m];
			k = v[m + 1];

			map->arcs[j][k] = 1;//����,���ſ�
			if (map->type == 0) {//���������ͼ
				map->arcs[k][j] = 1;//����,���ſ�
			}
		}
	}

	return map;
}

void printGraph(GraphMatrix *G, int a) {
	//���������ͼ���ڽӾ���
	if (a == 1) {
		int i, j;
		printf("Adjacency matrix:\n");
		for (i = 0; i < G->vcount; i++) {
			for (j = 0; j < G->vcount; j++)
				printf("%d ", G->arcs[i][j]);
			if (i != G->vcount - 1) printf("\n");
		}
	} else {
		FILE *fp = fopen("a1-1.txt", "w");
		char b = '\n';
		for (int i = 0; i < G->vcount; i++) {
			for (int j = 0; j < G->vcount; j++) {
				fputc(G->arcs[i][j] + 48, fp);
			}
			fputc(b, fp);
		}
	}
}

//�ڽӱ�洢
GraphList *initGraphList(int a) {
	GraphList *map = (GraphList *)malloc(sizeof(GraphList));

	int n;
	int j, k, i = 1;//��ʼ��,�յ�

	if (a == 1) {
		//����ͼ�����͡�ͼ�Ķ������ͱ���
		printf("enter the type of the graph (0->UndiGraph/1->DiGraph):\n");
		scanf("%d", &map->type);
		printf("enter the top point number of vertices(number<=6 is legal):\n");
		for (;;) {
			scanf("%d", &map->vcount);
			if (map->vcount <= 6) break;
			else printf("!!!illegal input!!!\n");
		}
		printf("enter the number of edges(number<=6 is legal):\n");
		for (;;) {
			scanf("%d", &n);
			if (n <= 6) break;
			else printf("!!!illegal input!!!\n");
		}

		char c[map->vcount];
		gets(c);//���տո�
		printf("enter vertex (corresponding subscript) information(enter with no space!):\n");
		gets(c);
		for (int i = 0; i < map->vcount; i++) {
			map->vexs[i].vertex = c[i];
		}
		//���붥������

		for (int i = 0; i < map->vcount; i++) {
			map->vexs[i].edgelist = NULL;
		}
		//�ڽӱ��ʼ��

		i = 1;
		printf("print the number of the start point and the end point of all sides:\n");
		while (i < n) {
			scanf("%d%d", &j, &k);//��j���������ӵ�k����ֱ������ͷ�ڵ����
			EdgeList s = (EdgeList)malloc(sizeof(struct EdgeNode));
			s->endvex = k;
			s->nextedge = map->vexs[j].edgelist;
			map->vexs[j].edgelist = s;

			if (map->type == 0) {//���������ͼ
				EdgeList s = (EdgeList)malloc(sizeof(struct EdgeNode));
				s->endvex = j;
				s->nextedge = map->vexs[k].edgelist;
				map->vexs[k].edgelist = s;
			}

			i++;
		}
	} else {
		char v[50];
		FILE *fp = fopen("a2.txt", "r");
		fgets(v, 50, fp);
		map->type = v[0] - 48;
		map->vcount = v[1] - 48;
		n = v[2] - 48;
		for (int i = 1; i <= map->vcount; i++)
			map->vexs[i - 1].vertex = v[i + 2];

		for (int i = 0; i < map->vcount; i++) {
			map->vexs[i].edgelist = NULL;
		}
		//�ڽӱ��ʼ��
		i = 1;
		int p = 8;
		while (i < n) {
			j = v[p] - 48;
			k = v[p + 1] - 48;
			EdgeList s = (EdgeList)malloc(sizeof(struct EdgeNode));
			s->endvex = k;
			s->nextedge = map->vexs[j].edgelist;
			map->vexs[j].edgelist = s;

			if (map->type == 0) {//���������ͼ
				EdgeList s = (EdgeList)malloc(sizeof(struct EdgeNode));
				s->endvex = j;
				s->nextedge = map->vexs[k].edgelist;
				map->vexs[k].edgelist = s;
			}

			i++;
			p += 2;
		}
	}

	return map;
}

//����ڽӱ�
void printGraphLit(GraphList *G, int a) {
	/*����ڽӱ������ʽ������->�ڽӶ�����->...*/
	if (a == 1) {
		printf("Adjacency List:\n");
		for (int i = 0; i < G->vcount; i++) {
			EdgeList p = G->vexs[i].edgelist;
			printf("%c", G->vexs[i].vertex);

			while (p != NULL) {
				printf("->%d", p->endvex);
				p = p->nextedge;
			}
			if (i != G->vcount - 1) printf("\n");
		}
	} else {
		FILE *fp = fopen("a2-1", "w");
		char a = '-';
		char b = '>';
		char c = '\n';
		for (int i = 0; i < G->vcount; i++) {
			EdgeList p = G->vexs[i].edgelist;
			fputc(G->vexs[i].vertex, fp);

			while (p != NULL) {
				fputc(a, fp);
				fputc(b, fp);
				fputc(p->endvex + 48, fp);
				p = p->nextedge;
			}
			if (i != G->vcount - 1) fputc(c, fp);
		}
	}
}

int main() {
	for (;;) {
		printf("choose(1/2/3)\n1->Storage of adjacency matrix\n2->Storage of adjacency list\n3->Dijkstra algorithm for finding the shortest path\n");

		int number;
		scanf("%d", &number);
		printf("whether you want to read information directly from the file?(yes/no)\n");
		char a[3];
		gets(a);
		if (number == 1) {
			gets(a);
			if (a[0] == 'y' && a[1] == 'e' && a[2] == 's') {
				//�ڽӾ���
				GraphMatrix *map = initGraphMatrix(0);
				printGraph(map, 0);

			} else if (a[0] == 'n' && a[1] == 'o') {
				//�ڽӾ���
				GraphMatrix *map = initGraphMatrix(1);
				printGraph(map, 1);
			} else {
				printf("!!!illegal input!!!\n");
			}

			break;
		} else if (number == 2) {
			gets(a);
			if (a[0] == 'y' && a[1] == 'e' && a[2] == 's') {
				//�ڽӱ�
				GraphList *list = initGraphList(0);
				printGraphLit(list, 0);

			} else if (a[0] == 'n' && a[1] == 'o') {
				//�ڽӱ�
				GraphList *list = initGraphList(1);
				printGraphLit(list, 1);
			} else {
				printf("!!!illegal input!!!\n");
			}

			break;
		} else if (number == 3) {
			gets(a);
			DMap *map;
			int n;//�������
			printf("enter the top point number of vertices:\n");
			scanf("%d", &n);
			if (a[0] == 'y' && a[1] == 'e' && a[2] == 's') {
				map = scanDijkastra(n, 0);
				map = Dijkastra(n, map);
				printDijkastra(n, map, 0);
			} else if (a[0] == 'n' && a[1] == 'o') {
				map = scanDijkastra(n, 1);
				map = Dijkastra(n, map);
				printDijkastra(n, map, 1);
			}
			break;
		} else {
			printf("!!!illegal input!!!\n");
		}
	}
}
