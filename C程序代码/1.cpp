#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

//ð������
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

//��������
void QuickSort(int *arr, int low, int high)  
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int k = arr[low];
		while (i < j)
		{
			while (i < j && arr[j] >= k)     // ���������ҵ�һ��С��k����
			{
				j--;
			}
 
			if (i < j)
			{
				arr[i++] = arr[j];
			}
 
			while (i < j && arr[i] < k)      // ���������ҵ�һ�����ڵ���k����
			{
				i++;
			}
 
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}
 
		arr[i] = k;
 
		// �ݹ����
		QuickSort(arr, low, i - 1);     // ����k���
		QuickSort(arr, i + 1, high);    // ����k�ұ�
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
	BubbleSort(num, n);		//ð������
	clock_t end = clock();
	
	printf("ð������Runing time is %ld  \n", (end - start));//<-
	getchar();

 	for (int i = 0; i<n; i++)
	{	
		num[i] = rand() % n;	
	}
	
	clock_t start2 = clock();
	QuickSort(num, 0, n-1);				//����
	clock_t end2 = clock();
	
	printf("��������Runing time is %ld ", (end2 - start2));
	
}
