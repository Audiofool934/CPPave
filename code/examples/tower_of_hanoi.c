#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    // printf("hanoi(%d, %c, %c, %c)\n", n, from, to, aux);
    if (n == 1) { // base case: 当只有一个圆盘时，直接移动
        printf("Move disk %d from %c to %c\n", n, from, to);
        return;
    }
    // divide/reduction: 将 n-1 个圆盘从 from 移到 aux，（借助 to）
    hanoi(n - 1, from, aux, to);
    // delegate: 将第 n 个圆盘从 from 移到 to, 这里的“操作”在形式上是移动圆盘
    printf("Move disk %d from %c to %c\n", n, from, to);
    // divide/reduction: 将 n-1 个圆盘从 aux 移到 to，（借助 from）
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B'); // 从 A 移到 C，（借助 B）
    return 0;
}