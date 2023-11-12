#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 检查坐标 (row, col) 是否在矩阵范围内
bool isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

// 使用深度优先搜索遍历岛屿
void dfs(int** grid, int row, int col, bool** visited, int rows, int cols) {
    visited[row][col] = true;  // 标记当前位置为已访问

    // 定义四个相邻位置的偏移量
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // 遍历当前位置的四个相邻位置
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (isValid(newRow, newCol, rows, cols) && !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
            dfs(grid, newRow, newCol, visited, rows, cols);  // 递归调用DFS
        }
    }
}

// 统计岛屿数量
int countIslands(int** grid, int rows, int cols) {
    bool** visited = (bool**)malloc(rows * sizeof(bool*));  // 创建visited数组
    for (int i = 0; i < rows; i++) {
        visited[i] = (bool*)malloc(cols * sizeof(bool));
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;  // 初始化visited数组，全部置为false
        }
    }

    int count = 0;  // 统计岛屿数量

    // 遍历整个矩阵
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {  // 如果当前位置未访问过且为陆地
                count++;  // 岛屿数量加1
                dfs(grid, i, j, visited, rows, cols);  // 调用DFS遍历岛屿
            }
        }
    }

    // 释放visited数组的内存
    for (int i = 0; i < rows; i++) {
        free(visited[i]);
    }
    free(visited);

    return count;
}

int main() {
	//输入 
    int rows, cols;
    scanf("%d,%d", &rows, &cols);
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int islandCount = countIslands(grid, rows, cols);
    int max;
    if(rows>cols) max=rows;
    else max=cols;
    if(islandCount>max) printf("buyyyyyy!"); 
    else printf("NextOne");
    
    // 释放动态分配的内存
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
