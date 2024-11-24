#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) { // 基准条件：当只有一个圆盘时，直接移动
        printf("Move disk %d from %c to %c\n", n, from, to);
        return;
    }
    // 步骤 1：将 n-1 个圆盘从 from 移到 aux，（借助 to）
    hanoi(n - 1, from, aux, to);
    // 步骤 2：将第 n 个圆盘从 from 移到 to
    printf("Move disk %d from %c to %c\n", n, from, to);
    // 步骤 3：将 n-1 个圆盘从 aux 移到 to，（借助 from）
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi for %d disks:\n", n);
    hanoi(n, 'A', 'C', 'B'); // 从 A 移到 C，（借助 B）
    return 0;
}