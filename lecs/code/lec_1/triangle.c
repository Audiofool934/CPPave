#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n; // 输入
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) // 数组排序
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] < a[j + 1]) {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    int max = 0;
    for (int i = 0; i < n - 2; i++)
        if (a[i] - a[i + 1] < a[i + 2]) {
            max = a[i] + a[i + 1] + a[i + 2];
            break;
        }
    printf("%d", max);
    
    return 0;
}