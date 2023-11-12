#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ������� (row, col) �Ƿ��ھ���Χ��
bool isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

// ʹ���������������������
void dfs(int** grid, int row, int col, bool** visited, int rows, int cols) {
    visited[row][col] = true;  // ��ǵ�ǰλ��Ϊ�ѷ���

    // �����ĸ�����λ�õ�ƫ����
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // ������ǰλ�õ��ĸ�����λ��
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (isValid(newRow, newCol, rows, cols) && !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
            dfs(grid, newRow, newCol, visited, rows, cols);  // �ݹ����DFS
        }
    }
}

// ͳ�Ƶ�������
int countIslands(int** grid, int rows, int cols) {
    bool** visited = (bool**)malloc(rows * sizeof(bool*));  // ����visited����
    for (int i = 0; i < rows; i++) {
        visited[i] = (bool*)malloc(cols * sizeof(bool));
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;  // ��ʼ��visited���飬ȫ����Ϊfalse
        }
    }

    int count = 0;  // ͳ�Ƶ�������

    // ������������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {  // �����ǰλ��δ���ʹ���Ϊ½��
                count++;  // ����������1
                dfs(grid, i, j, visited, rows, cols);  // ����DFS��������
            }
        }
    }

    // �ͷ�visited������ڴ�
    for (int i = 0; i < rows; i++) {
        free(visited[i]);
    }
    free(visited);

    return count;
}

int main() {
	//���� 
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
    
    // �ͷŶ�̬������ڴ�
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
