//DP

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int target;
        scanf("%d", &target);
        int row = 0, col = n - 1;
        while(row < n && col >= 0) {
            if(matrix[row][col] == target) {
                printf("%d %d\n", row, col);
                break;
            } else if(matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        if(row == n || col == -1) {
            printf("-1\n");
        }
    }
    return 0;
}





#include <stdio.h>
#include <stdbool.h>

// 定义一个函数，用于在二维数组中查找一个数字
bool find(int matrix[][100], int n, int target, int *row, int *col) {
    // 从右上角开始查找
    int i = 0; // 行索引
    int j = n - 1; // 列索引
    while (i < n && j >= 0) {
        if (matrix[i][j] == target) { // 找到了
            *row = i; // 返回行号
            *col = j; // 返回列号
            return true; // 返回真
        } else if (matrix[i][j] > target) { // 当前元素大于目标，向左移动
            j--;
        } else { // 当前元素小于目标，向下移动
            i++;
        }
    }
    return false; // 没有找到，返回假
}

int main() {
    int n; // 二维数组的行数和列数
    int matrix[100][100]; // 二维数组
    int k; // 待查找的数字的个数
    int targets[100]; // 待查找的数字数组
    int row, col; // 数字所在的行号和列号

    // 输入二维数组的行数和列数
    scanf("%d", &n);

    // 输入二维数组的元素
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 输入待查找的数字的个数
    scanf("%d", &k);

    // 输入待查找的数字
    for (int i = 0; i < k; i++) {
        scanf("%d", &targets[i]);
    }

    // 对每个待查找的数字，调用find函数，输出结果
    for (int i = 0; i < k; i++) {
        if (find(matrix, n, targets[i], &row, &col)) { // 如果找到了
            printf("%d %d\n", row, col); // 输出行号和列号
        } else { // 如果没找到
            printf("-1\n"); // 输出-1
        }
    }

    return 0;
}



