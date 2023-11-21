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

//输入map,传入顶点个数
DMap* scanDijkastra(int n, int a) {
	int m;//边的个数
	char v[20];
	if (a == 1) {
		printf("enter the number of edges:\n");
		scanf("%d", &m);
		printf("Enter the weights of the starting point, end point, and the number of all sides:\n");
		for (int i = 0; i < m; i++) {
			int a, b, c; //起点,终点,权值
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
		//建立权值矩阵
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
			int a, b, c; //起点,终点,权值
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
	//将矩阵的第一行赋为权值的初始值

	return map;
}

//传入map,顶点个数 ,输出A到个点的最短路径
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

// Dijkastra算法求点A到各点的最短路径
//传入顶点个数和map
DMap* Dijkastra(int n, DMap *map) {
	int min = 0, minn = 0;
	for (int i = 0; i < n; i++) {
		if (map->record[i] != 0) {
			min = map->record[i];
			minn = i;
			break;
		}
	}
	//找record数组中第一个非0的值赋为min的初始值,minn标记位置

	for (int i = 1; i < n; i++)//
		if (map->record[i] != 0)
			if (min > map->record[i]) {
				min = map->record[i];
				minn = i;
			}
	map->record[minn] = 0;
	//找到不为0的record数组中最小的那个数,将record数组的那个值记为0

	for (int i = 0; i < n; i++)
		if (map->record[i] != 0)
			if (map->moon[minn] + graph[minn][i] < map->moon[i])
				map->moon[i] = map->moon[minn] + graph[minn][i];
	//更新权值

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (map->record[i] != 0) {
			m = 1;
			break;
		}
	}
	if (m == 0) return map;
	//如果moon数组都为0,跳出

	Dijkastra(n, map);//递归
}

//邻接矩阵数据结构
typedef struct {
	int vcount;     //顶点数
	int type;       // 0 无向图，1 有向图
	char vexs[N];   // 顶点信息
	int arcs[N][N]; //关系矩阵
	int mon[N][N];  //权值
} GraphMatrix;

//邻接表数据结构
struct EdgeNode {
	int endvex;                //对应顶点的边表下标
	int weight;                //边的权
	struct EdgeNode *nextedge; //链字段
};
typedef struct EdgeNode *EdgeList;

//顶点表
typedef struct {
	char vertex;       //记录顶点的信息
	int degree;        //用于记录顶点的入度，在拓扑排序时需使用
	EdgeList edgelist; //指向边表的指针
} VexNode;

//邻接表
typedef struct {
	VexNode vexs[N]; // N个顶点
	int type;        // 0无向图，1有向图
	int vcount;      //顶点数
} GraphList;

//图的初始化
//邻接矩阵存储
GraphMatrix *initGraphMatrix(int a) {
	GraphMatrix *map = (GraphMatrix *)malloc(sizeof(GraphMatrix));
	int n;
	char v[20];
	if (a == 1) {
		//输入图的类型、图的顶点数和边数
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

	for (int i = 0; i < map->vcount; i++)//形成以map->vcount为边的正方形矩阵,初始为0
		for (int j = 0; j < map->vcount; j++)
			map->arcs[i][j] = 0;

	int j, k;
	if (a == 1) {
		int i = 0;
		printf("print the number of the start point and the end point of all sides:\n");
		while (i < n) {
			scanf("%d%d", &j, &k);//输入各条边的两顶点的编号

			map->arcs[j][k] = 1;//正向,横着看
			if (map->type == 0) {//如果是无向图
				map->arcs[k][j] = 1;//逆向,竖着看
			}

			i++;
		}
	} else {
		for (int i = 0, m = 3; i < n; i++, m += 2) {
			j = v[m];
			k = v[m + 1];

			map->arcs[j][k] = 1;//正向,横着看
			if (map->type == 0) {//如果是无向图
				map->arcs[k][j] = 1;//逆向,竖着看
			}
		}
	}

	return map;
}

void printGraph(GraphMatrix *G, int a) {
	//本函数输出图的邻接矩阵
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

//邻接表存储
GraphList *initGraphList(int a) {
	GraphList *map = (GraphList *)malloc(sizeof(GraphList));

	int n;
	int j, k, i = 1;//起始点,终点

	if (a == 1) {
		//输入图的类型、图的顶点数和边数
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
		gets(c);//吸收空格
		printf("enter vertex (corresponding subscript) information(enter with no space!):\n");
		gets(c);
		for (int i = 0; i < map->vcount; i++) {
			map->vexs[i].vertex = c[i];
		}
		//输入顶点数据

		for (int i = 0; i < map->vcount; i++) {
			map->vexs[i].edgelist = NULL;
		}
		//邻接表初始化

		i = 1;
		printf("print the number of the start point and the end point of all sides:\n");
		while (i < n) {
			scanf("%d%d", &j, &k);//第j个顶点连接第k个点直接连在头节点后面
			EdgeList s = (EdgeList)malloc(sizeof(struct EdgeNode));
			s->endvex = k;
			s->nextedge = map->vexs[j].edgelist;
			map->vexs[j].edgelist = s;

			if (map->type == 0) {//如果是无向图
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
		//邻接表初始化
		i = 1;
		int p = 8;
		while (i < n) {
			j = v[p] - 48;
			k = v[p + 1] - 48;
			EdgeList s = (EdgeList)malloc(sizeof(struct EdgeNode));
			s->endvex = k;
			s->nextedge = map->vexs[j].edgelist;
			map->vexs[j].edgelist = s;

			if (map->type == 0) {//如果是无向图
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

//输出邻接表
void printGraphLit(GraphList *G, int a) {
	/*输出邻接表，输出格式：顶点->邻接顶点编号->...*/
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
				//邻接矩阵
				GraphMatrix *map = initGraphMatrix(0);
				printGraph(map, 0);

			} else if (a[0] == 'n' && a[1] == 'o') {
				//邻接矩阵
				GraphMatrix *map = initGraphMatrix(1);
				printGraph(map, 1);
			} else {
				printf("!!!illegal input!!!\n");
			}

			break;
		} else if (number == 2) {
			gets(a);
			if (a[0] == 'y' && a[1] == 'e' && a[2] == 's') {
				//邻接表
				GraphList *list = initGraphList(0);
				printGraphLit(list, 0);

			} else if (a[0] == 'n' && a[1] == 'o') {
				//邻接表
				GraphList *list = initGraphList(1);
				printGraphLit(list, 1);
			} else {
				printf("!!!illegal input!!!\n");
			}

			break;
		} else if (number == 3) {
			gets(a);
			DMap *map;
			int n;//顶点个数
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
