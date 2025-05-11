#include<stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define N 8
int queen[N] = {0}; 
int count = 0; 
int check(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queen[i] == col || row - i == col - queen[i] || row - i == queen[i] - col) {
            return 0;
        }
    }
    return 1;
}
void backtrack(int row) {
    if (row == N) { 
        count++;
        return;
    }
    for (int i = 0; i < N; i++) { 
        if (check(row, i)) {
            queen[row] = i;
            backtrack(row + 1);
            queen[row] = 0;
        }
    }
}
//用回溯法编程实现八皇后问题求解
int main()
{
/************ Begin ************/
    backtrack(0); 
    printf("%d", count);
/************ End *************/
return 0;
}
