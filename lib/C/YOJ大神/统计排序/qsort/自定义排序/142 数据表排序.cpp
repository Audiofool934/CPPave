#include <stdio.h>
#include <stdlib.h>

int m, n, k;
int sortColumns[100];  // 存储排序依据的列号
int **data;  // 用于存储二维数据表

// 自定义比较函数，用于排序
int compare(const void *a, const void *b) {
    int *rowA = *(int **)a;
    int *rowB = *(int **)b;
    for (int i = 0; i < k; i++) {
        int col = sortColumns[i] - 1;  // 调整列号以适应数组索引
        if (rowA[col] != rowB[col]) {
            return rowA[col] - rowB[col];
        }
    }
    return rowA[0] - rowB[0];  // 如果所有排序依据列相等，则按第一列排序
}

int main() {
    // 读取输入
    scanf("%d %d", &m, &n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &sortColumns[i]);
    }

    // 分配内存并读取数据表
    data = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        data[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    // 排序
    qsort(data, m, sizeof(int *), compare);

    // 输出排序后的数据表
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
        free(data[i]);  // 释放内存
    }
    free(data);  // 释放内存

    return 0;
}