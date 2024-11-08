#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 比较函数，首先比较生日，然后比较整个身份证号
int compare(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    // 首先比较生日部分
    int result = strncmp(str1 + 6, str2 + 6, 8);
    if (result == 0) {
        // 如果生日相同，比较整个身份证号
        return -strcmp(str1, str2);
    }
    return -result;
}

int main() {
    int n;
    scanf("%d", &n);
    char id[100010][19];
    char* id_ptrs[100010];

    // 从0开始遍历数组
    for(int i = 0; i < n; i++) {
        scanf("%s", id[i]);
        id_ptrs[i] = id[i];
    }

    // 使用 qsort 对 id_ptrs 进行排序
    qsort(id_ptrs, n, sizeof(char*), compare);

    // 打印排序后的结果
    for(int i = 0; i < n; i++) {
        printf("%s\n", id_ptrs[i]);
    }

    return 0;
}
