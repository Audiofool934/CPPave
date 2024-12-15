#include <stdio.h>
#include <stdbool.h>

#define MAXN 10

int n; // 人数（也等于书的数量）
int preference[MAXN][MAXN]; // 存储每个人对每本书的喜好
bool used[MAXN]; // 标记某本书是否已被分配
int allocation[MAXN]; // 当前的分配方案
int totalSolutions = 0; // 总方案数

// 递归生成所有分配方案
void findAllocations(int person) {
    if (person == n) {
        // 所有人的书都已分配，打印当前方案
        totalSolutions++;
        for (int i = 0; i < n; i++) {
            printf("B%d", allocation[i] + 1);
        }
        printf("\n");
        return;
    }

    for (int book = 0; book < n; book++) {
        // 如果这本书已经分配，或者这个人不喜欢这本书，跳过
        if (used[book] || preference[person][book] == 0) {
            continue;
        }

        // 分配书给当前人
        used[book] = true;
        allocation[person] = book;

        // 递归分配下一个人的书
        findAllocations(person + 1);

        // 回溯，撤销分配
        used[book] = false;
    }
}

int main() {
    // 输入人数和书的数量
    scanf("%d", &n);

    // 输入每个人对每本书的喜好
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &preference[i][j]);
        }
    }

    // 初始化标记数组
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    // 寻找所有分配方案
    findAllocations(0);

    // 如果没有方案，输出NO
    if (totalSolutions == 0) {
        printf("NO\n");
    } else {
        printf("%d\n", totalSolutions); // 输出总方案数
    }

    return 0;
}