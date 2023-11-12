#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

//冒泡排序
void BubbleSort(int *a, int length) 
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//快速排序
void QuickSort(int *arr, int low, int high)  
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int k = arr[low];
		while (i < j)
		{
			while (i < j && arr[j] >= k)     // 从右向左找第一个小于k的数
			{
				j--;
			}
 
			if (i < j)
			{
				arr[i++] = arr[j];
			}
 
			while (i < j && arr[i] < k)      // 从左向右找第一个大于等于k的数
			{
				i++;
			}
 
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}
 
		arr[i] = k;
 
		// 递归调用
		QuickSort(arr, low, i - 1);     // 排序k左边
		QuickSort(arr, i + 1, high);    // 排序k右边
	}
}
 
int main(void)
{
	long long int n;
	scanf("%Ld",&n);
	int num[n];
	
 	srand(time(0));
	for (int i = 0; i<n; i++)
	{
		num[i] = rand() % n;
	}

	clock_t start = clock();
	BubbleSort(num, n);		//冒泡排序
	clock_t end = clock();
	
	printf("冒泡排序Runing time is %ld  \n", (end - start));//<-
	getchar();

 	for (int i = 0; i<n; i++)
	{	
		num[i] = rand() % n;	
	}
	
	clock_t start2 = clock();
	QuickSort(num, 0, n-1);				//快排
	clock_t end2 = clock();
	
	printf("快速排序Runing time is %ld ", (end2 - start2));
	
}
