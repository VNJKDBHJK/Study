#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void Print(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void RangedRandDemo( int range_min, int range_max, int n, int* a) {
	//输入值范围,随机数个数
	int i;
	for ( i = 0; i < n; i++ ) {
		int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
		a[i] = u;
	}
}

void swap(int a, int b) {
	int m;
	m = a;
	a = b;
	m = b;
}

void maopao(int a[], int n) {
	int i, j;
	int len = n;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}

int main() {
	clock_t start_time1 = clock();
	//开始计时
	int n;
	scanf("%d", &n);
	int array1[n];
	srand( (unsigned)time( NULL ) );//随机数种子
	RangedRandDemo( -100, 100, n, array1);
	//生成数组
	printf("冒泡排序初始数组:");
	Print(array1, n);
	maopao(array1, n);

	printf("冒泡排序后数组:");
	Print(array1, n);

	printf("Runing time is %.2f s", (double)(clock() - start_time1) / CLOCKS_PER_SEC);
}
