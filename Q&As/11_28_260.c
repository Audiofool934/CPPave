#include <stdio.h>
#include <stdlib.h>
#include <algorithm>  // for std::sort

#define MAX_SIZE 1000  // 假设数组大小为1000，如果需要可以调整

int a[MAX_SIZE];  // 存储输入的数组

void search(int x, int l, int h, int *count, int *ans) {
    int mid = (l + h) / 2;
    // (*count)++;
    if (l > h) {
        *ans = -1;
        return;
    }
    if (x == a[mid]) {
        (*count)++;
        *ans = mid;
        return;
    }
    else if (x > a[mid]) {
        (*count)++;
        search(x, mid + 1, h, count, ans);
    }
    else {
        (*count)++;
        search(x, l, mid - 1, count, ans);
    }
}

int main() {
    int n, m, i, count = 0, ans = -1;
    
    // 输入数组的大小和要查找的元素
    scanf("%d", &n);  // 输入数组元素的个数
    scanf("%d", &m);  // 输入要查找的目标值
    
    // 输入数组元素
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // 对数组进行排序
    std::sort(a, a + n);
    
    // 调用二分查找函数
    search(m, 0, n - 1, &count, &ans);
    
    // 输出结果：查找结果的下标和比较次数
    printf("%d\n%d", ans, count);
    
    return 0;
}
