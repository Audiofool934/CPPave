#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "tfeeefst";
    char str2[] = "teeest";
    printf("%d\n", strncmp(str1+2, str2+2, 2));
    return 0;
}