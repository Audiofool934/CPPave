#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, k;
    scanf("%d%d", &m, &k);
    int n, a[10000][4] = {0}, count = 0;
    // n是每行第一个数字；四维数组a分别记录类别号、坐标点、距离；数组b记录;count记录所有的样本数

    for (int i = 0; i < m; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d%d", &a[count][1], &a[count][2]);
            a[count++][0] = i;
        }
    }
    int x0, y0;
    scanf("%d%d", &x0, &y0);
    for (int i = 0; i < count; i++)
        a[i][3] = (a[i][1] - x0) * (a[i][1] - x0) + (a[i][2] - y0) * (a[i][2] - y0);
    int ex;
    for (int i = 1; i < count; i++)
        for (int j = i - 1; j >= 0; j--)
            if (a[j][3] > a[j + 1][3]) { // 冒泡排序（按距离降序，距离相同按类别号降序）
                ex = a[j][0];
                a[j][0] = a[j + 1][0];
                a[j + 1][0] = ex;
                ex = a[j][3];
                a[j][3] = a[j + 1][3];
                a[j + 1][3] = ex;
            } else if (a[j][3] == a[j + 1][3] && a[j][0] > a[j + 1][0]) {
                ex = a[j][0];
                a[j][0] = a[j + 1][0];
                a[j + 1][0] = ex;
            }
    if (count < k) // 样本总数小于k时，考虑所有样本
        k = count;
    int num = k; // num记录最邻近样本个数
    if (k != count) { // 第k个之后的多个样本到待分类样本的距离==最相似的第k个样本到待分类样本的距离时，都考虑
        for (num = k; num < count; num++)
            if (a[num][3] > a[k - 1][3])
                break;
    }
    int b[100] = {0}, max0 = 0;
    for (int i = 0; i < num; i++) // 每类满足要求的个数
        b[a[i][0]]++;
    for (int i = 0; i < m; i++) // 共m组类别，找出最大值
        if (b[i] > max0)
            max0 = b[i];
    for (int i = 0; i < m; i++) // 输出最大值
        if (b[i] == max0) {
            printf("%d", i + 1);
            break;
        }

    return 0;
}