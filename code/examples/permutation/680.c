#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sticks[10]; // 保存棍子长度
bool used[10];  // 标记棍子是否被使用
int n, targetLen, totalSum;

// 按降序排序函数（为减少回溯深度）
int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

// 回溯函数
bool backtrack(int currentLen, int stickCount, int index) {
    // 如果已经完成所有的棍子
    if (stickCount == totalSum / targetLen) {
        return true;
    }

    // 如果当前棍子的长度完成，开始下一根
    if (currentLen == targetLen) {
        return backtrack(0, stickCount + 1, 0);
    }

    // 尝试选择棍子
    for (int i = index; i < n; i++) {
        if (used[i]) continue; // 跳过已用棍子
        if (currentLen + sticks[i] > targetLen) continue; // 棍子太长

        // 避免重复组合
        if (i > 0 && sticks[i] == sticks[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        if (backtrack(currentLen + sticks[i], stickCount, i + 1)) {
            return true;
        }
        used[i] = false;

        // 剪枝：如果当前组合失败，后续相同长度的棍子也会失败
        if (currentLen == 0 || currentLen + sticks[i] == targetLen) {
            return false;
        }
    }
    return false;
}

int main() {
    // 输入
    scanf("%d", &n);
    totalSum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &sticks[i]);
        totalSum += sticks[i];
    }

    // 按降序排列以优化回溯
    qsort(sticks, n, sizeof(int), cmp);

    // 枚举可能的原始棍长
    for (targetLen = sticks[0]; targetLen <= totalSum; targetLen++) {
        if (totalSum % targetLen != 0) continue; // 必须是总长度的因数

        // 初始化标记数组
        for (int i = 0; i < n; i++) used[i] = false;

        // 如果可以成功组合，输出结果并退出
        if (backtrack(0, 0, 0)) {
            printf("%d\n", targetLen);
            return 0;
        }
    }
    return 0;
}