#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    int num = 0, sum = 0, tmp = 0; // 以过道为间隔分组，num是每组的座位数；tmp记录每行的最大容纳人数
    for (int i = 0; i < m; i++) {
        if (a[0][i] == 0)
            num++;
        if (a[0][i] == 1 || i == m - 1) {
            tmp += (num + 1) / 2;
            sum += num * (n / 2);
            num = 0;
        }
    }

    if (n % 2 == 0)
        printf("%d", sum);
    else if (n % 2 == 1)
        printf("%d", sum + tmp);

    system("pause");
    return 0;
}