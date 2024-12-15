#include <stdio.h>
#include <stdbool.h>

#define MAXN 10

int n, targetSum;
int currentPermutation[MAXN];
bool used[MAXN];
bool foundSolution = false;

// 计算当前序列最终合并的结果
int calculateSum(int sequence[], int n) {
    int temp[MAXN];
    for (int i = 0; i < n; i++) {
        temp[i] = sequence[i];
    }
    
    while (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            temp[i] = temp[i] + temp[i + 1];
        }
        n--;
    }
    return temp[0];
}

// 递归生成排列并验证
void findPermutation(int depth) {
    if (depth == n) {
        // 当生成一个完整的排列时，计算最终合并的结果
        if (calculateSum(currentPermutation, n) == targetSum) {
            if (!foundSolution) {
                // 输出满足条件的第一个排列（字典序最小）
                for (int i = 0; i < n; i++) {
                    if (i > 0) printf(" ");
                    printf("%d", currentPermutation[i]);
                }
                printf("\n");
                foundSolution = true; // 标记已找到解
            }
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i] && !foundSolution) {
            used[i] = true;
            currentPermutation[depth] = i;
            findPermutation(depth + 1);
            used[i] = false; // 回溯
        }
    }
}

int main() {
    // 输入 n 和目标和 targetSum
    scanf("%d %d", &n, &targetSum);

    // 初始化 used 数组
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    // 递归生成排列并寻找解
    findPermutation(0);

    return 0;
}