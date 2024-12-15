#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 检查一个数字是否与 Wild 号码匹配
bool matchesWildCode(const char* wild, const char* number) {
    int length = strlen(wild);
    for (int i = 0; i < length; i++) {
        if (wild[i] != '?' && wild[i] != number[i]) {
            return false; // 如果遇到不匹配情况，返回 false
        }
    }
    return true; // 所有位置匹配，返回 true
}

// 递归生成所有可能的数字组合
void generateNumbers(const char* wild, char* current, int pos, int* count, const char* W) {
    int length = strlen(wild);
    if (pos == length) {
        // 已经生成一个完整的数字，检查是否满足条件
        if (strcmp(current, W) > 0) {
            (*count)++;
        }
        return;
    }

    if (wild[pos] == '?') {
        // 如果当前字符是 '?', 尝试替换成 '0' 到 '9'
        for (char c = '0'; c <= '9'; c++) {
            current[pos] = c;
            generateNumbers(wild, current, pos + 1, count, W);
        }
    } else {
        // 如果当前字符不是 '?', 直接复制
        current[pos] = wild[pos];
        generateNumbers(wild, current, pos + 1, count, W);
    }
}

int main() {
    char wild[11]; // Wild 号码，长度不超过 10
    char W[11];    // 输入的数字
    char current[11]; // 当前生成的数字
    int count;     // 计数器

    while (1) {
        // 输入 Wild 号码
        scanf("%s", wild);
        if (strcmp(wild, "#") == 0) {
            break; // 如果输入的是 "#"，退出循环
        }
        // 输入数字 W
        scanf("%s", W);

        // 初始化
        count = 0;
        memset(current, 0, sizeof(current));

        // 递归生成所有可能的数字并计数
        generateNumbers(wild, current, 0, &count, W);

        // 输出匹配数量
        printf("%d\n", count);
    }

    return 0;
}