#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(const char *str, const char *sub) {
    while (*sub) {
        // 在str中查找当前sub字符
        while (*str && *str != *sub) {
            str++;
        }

        // 如果str结束了但sub还有字符，返回false
        if (!*str) {
            return false;
        }

        // 移动到下一个字符
        str++;
        sub++;
    }
    return true;
}

int main() {
    char str[1000];
    char sub[1000];
    scanf("%s%s",str,sub);
    if (isSubsequence(str, sub)) {
        printf("'%s' 是 '%s' 的广义子串。\n", sub, str);
    } else {
        printf("'%s' 不是 '%s' 的广义子串。\n", sub, str);
    }

    return 0;
}
