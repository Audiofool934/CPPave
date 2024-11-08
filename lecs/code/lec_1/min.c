#include <stdio.h>
#include <stdlib.h>

int main() {
    int m; // 输入的m
    scanf("%d", &m);
    int a[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);

    int min = 1000;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            int tmp = abs(a[i] - a[j]);
            if (tmp < min)
                min = tmp;
        }
    }
    printf("%d", min);
    return 0;
}