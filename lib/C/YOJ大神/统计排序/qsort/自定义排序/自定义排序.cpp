#include <stdio.h>
#include <stdlib.h>

#define M 5 // 假设每行有 M 列

// 比较函数
int compareRows(const void* a, const void* b) {
    const int* rowA = *(const int**)a;
    const int* rowB = *(const int**)b;

    for (int i = 0; i < M; i++) {
        if (rowA[i] != rowB[i]) {
            return rowA[i] - rowB[i];
        }
    }
    return 0;
}

int main() {
    int n; // 数组的行数
    printf("请输入二维数组的行数: ");
    scanf("%d", &n);

    int array[n][M]; // 创建二维数组

    printf("请输入二维数组的元素（%d 行, %d 列）:\n", n, M);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    // 对二维数组进行排序
    qsort(array, n, sizeof(array[0]), compareRows);

    // 打印排序后的结果
    printf("排序后的数组:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
