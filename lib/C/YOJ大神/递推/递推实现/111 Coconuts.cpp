#include <stdio.h>
#include <math.h>

int check(int n, int m) {
    // 检查是否满足条件（有很多种方法）
    int cnt = 0;
    while (true) {
        cnt++;
        if ((cnt == m + 1) && (n % m == 0)) {
            // “第 m + 1 天，将剩下的 coconuts 恰好平均分成 m 份，且没有剩余的 coconuts 了”
            return 1;
        }
        if (n < m || n % m != 1 || cnt > m + 1) {
            return 0;
        }
        n = n - ( n / m ) - 1;
    }
}

int main() {
    int n, cn;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        cn = 1;
        for (int i = sqrt(n - 1); i >= 1; i--) {
            // 内循环遍历所有可能的m值，找到一个合适的m值就输出并跳出循环
            if (check(n, i)) {
                printf("%d\n", i);
                cn = 0;
                break;
            }
        }
        if (cn) {
            printf("no solution\n");
        }
    }
    return 0;
}
