#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100 // 假设迷宫的最大尺寸
#define MAX_PATHS 1000 // 假设最多路径数量
#define MAX_PATH_LENGTH 1000 // 假设单路径最大长度

int maze[MAX_N][MAX_N]; // 存储迷宫
int fp[MAX_N][MAX_N];   // 标记是否访问过的数组
int n, m;               // 迷宫尺寸

int paths[MAX_PATHS][MAX_PATH_LENGTH][2]; // 存储所有路径
int path_count = 0;     // 当前路径数量
int current_path[MAX_PATH_LENGTH][2]; // 当前路径
int current_length = 0; // 当前路径长度

void go(int x, int y) {
    // 边界条件和障碍物处理
    if (x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == 0 || fp[x][y] == 1) {
        return;
    }

    // 如果到达终点，记录路径
    if (x == n - 1 && y == m - 1) {
        current_path[current_length][0] = x;
        current_path[current_length][1] = y;
        current_length++;

        // 保存当前路径
        for (int i = 0; i < current_length; i++) {
            paths[path_count][i][0] = current_path[i][0];
            paths[path_count][i][1] = current_path[i][1];
        }
        path_count++;

        current_length--;
        return;
    }

    // 标记当前位置
    fp[x][y] = 1;
    current_path[current_length][0] = x;
    current_path[current_length][1] = y;
    current_length++;

    // 四个方向递归
    go(x + 1, y); // 向下
    go(x, y + 1); // 向右
    go(x - 1, y); // 向上
    go(x, y - 1); // 向左

    // 回溯
    fp[x][y] = 0;
    current_length--;
}

int main() {
    // 输入迷宫大小
    printf("Enter maze dimensions (n m): ");
    scanf("%d %d", &n, &m);

    // 输入迷宫
    printf("Enter maze (0 for wall, 1 for path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // 初始化fp数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fp[i][j] = 0;
        }
    }

    // 计算路径
    go(0, 0);

    // 输出所有路径
    printf("All paths:\n");
    for (int i = 0; i < path_count; i++) {
        for (int j = 0; paths[i][j][0] != 0 || paths[i][j][1] != 0; j++) {
            printf("(%d, %d) ", paths[i][j][0], paths[i][j][1]);
        }
        printf("\n");
    }

    return 0;
}