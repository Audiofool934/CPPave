#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char last_name[61];

    // 读取输入的数量和姓氏
    scanf("%d %s", &n, last_name);

    int jieguo[100];
    int j = 0;

    // 读取每行输入并比较
    for (int i = 0; i < n; i++) {
        int year;
        char a[61], b[61];
        scanf("%d %s %s", &year, a, b);

        if (strcmp(a, last_name) == 0) {
            jieguo[j] = year;
            j++;
        }
    }

    // 对年级进行排序
    for (int x = 0; x < j - 1; x++) {
        for (int y = 0; y < j - x - 1; y++) {
            if (jieguo[y] > jieguo[y + 1]) {
                int temp = jieguo[y];
                jieguo[y] = jieguo[y + 1];
                jieguo[y + 1] = temp;
            }
        }
    }

    int tag = 0, num = 1;

    // 输出结果
    for (int x = 0; x < j - 1; x++) {
        if (jieguo[x] == jieguo[x + 1]) {
            num++;
        } else {
            printf("%d %d\n", jieguo[x], num);
            tag++;
            num = 1;
        }
    }

    // 处理最后一个元素
    if (tag == 0) {
        printf("NONE");
    } else {
        printf("%d %d\n", jieguo[j - 1], num);
    }

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     int n;
//     char last_name[61];
//     scanf("%d %s", &n, last_name);
//     int jieguo[100];
//     int j = 0;
//     for (int i = 0; i < n; i++) { // 每行输入并比较
//         int year;
//         char a[61], b[61];
//         scanf("%d %s %s", &year, a, b);
//         if (strcmp(a, last_name) == 0) {
//             jieguo[j] = year;
//             j++;
//         }
//     }

//     for (int x = 0; x < j - 1; x++) { // 年级排序
//         for (int y = 0; y < j - x - 1; y++) {
//             if (jieguo[y] > jieguo[y + 1]) {
//                 int temp;
//                 temp = jieguo[y];
//                 jieguo[y] = jieguo[y + 1];
//                 jieguo[y + 1] = temp;
//             }
//         }
//     }

//     int tag = 0, num = 1;
//     for (int x = 0; x < j - 1; x++) {
//         if (jieguo[x] == jieguo[x + 1])
//             num++;
//         else {
//             printf("%d %d\n", jieguo[x], num);
//             tag++;
//             num = 1;
//         }
//     }
//     if (tag == 0)
//         printf("NONE");
//     else
//         printf("%d %d\n", jieguo[j - 1], num);

//     return 0;
// }