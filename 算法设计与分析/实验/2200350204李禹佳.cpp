/*
本关任务：给定N个物品和一个背包，背包的容量为W， 假设背包容量范围在[0，15]，第i个物品对应的体积和价值分别为W[i]和v[i]。各种物品的价值和重量如下：
     物品编号   1   2   3   4   5
      重量W    3   4   7   8   9
      价值V    4   5   10  11  13
求: 如何选择装入背包的物品，使得装入背包的物品的总价值为最大。

*/
#include <stdio.h>

int content[6] = {0};            //最优解的物品组成
int w[6] = {0, 3, 4, 7, 8, 9};   //物品对应的重量
int v[6] = {0, 4, 5, 10, 11, 13}; //物品对应的价值
int bV = 15;                     //背包的最大容量为15
int maxVal[6][16] = {0};        //存放当物品数为i,背包容量为j的最大总价值

void findContent(int i, int j);  //找到最优解的物品组成

void findMax();                 //寻找当物品数为i,背包容量为j时的最大总价值

int main( void )
{
	int i, j;
	printf("w v 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n");
	findMax();
	for (int i = 0; i < 6; i++) //打印当物品数为i,背包容量为j时的最大总价值
	{
		printf("%d %d ", w[i], v[i]);
		for (int j = 0; j < 16; j++)
		{
			printf("%d", maxVal[i][j]);
			if (j != 15)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return  0;
}

void findMax() //寻找当物品数为i,背包容量为j时的最大总价值
{
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 16; j++)
		{
			if (j < w[i])       //如果背包容量小于物品i重量，表示背包存放不下第i种物品,此时的最大总价值为i-1种物品的最大总价值
				maxVal[i][j] = maxVal[i - 1][j];
			else
			{
				if (maxVal[i - 1][j] > (maxVal[i - 1][j - w[i]] + v[i])) //放下第i种物品时的总价值为第i种物品的价值加上当物品数为i-1背包容量为j-w[i]的最优解
					maxVal[i][j] = maxVal[i - 1][j];         // 对比当放下第i种物品时的总价值和物品数位i-1时的总价值，取最大值
				else
					maxVal[i][j] = maxVal[i - 1][j - w[i]] + v[i];
			}

		}

}
