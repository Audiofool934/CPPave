#include <stdio.h>
#include <stdbool.h>

#define MAXN 9 // 最大矩阵阶数

int n; // 矩阵阶数
int matrix[MAXN][MAXN]; // 输入的矩阵
bool used[MAXN]; // 标记是否使用某个元素
int permutation[MAXN]; // 当前排列
int det = 0; // 最终行列式值

// 计算当前排列的逆序数
int countInversions(int arr[], int size) {
    int inversions = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

// 递归生成排列并计算行列式
void calculateDeterminant(int depth) {
    if (depth == n) {
        // 当生成一个完整的排列时，计算贡献值
        int inversions = countInversions(permutation, n); // 计算逆序数
        int sign = (inversions % 2 == 0) ? 1 : -1; // 根据逆序数确定符号
        int product = sign; // 计算排列对应的乘积

        for (int i = 0; i < n; i++) {
            product *= matrix[i][permutation[i]];
        }

        det += product; // 将当前排列的贡献加到行列式值
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            permutation[depth] = i;
            calculateDeterminant(depth + 1);
            used[i] = false; // 回溯
        }
    }
}

int main() {
    // 输入矩阵阶数
    scanf("%d", &n);

    // 输入矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 初始化used数组
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    // 递归生成排列并计算行列式
    calculateDeterminant(0);

    // 输出行列式值
    printf("%d\n", det);

    return 0;
}