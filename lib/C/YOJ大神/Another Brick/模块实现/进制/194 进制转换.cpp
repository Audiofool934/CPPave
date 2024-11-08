#include <stdio.h>

void convert(int num, int base) {
    if (num == 0) {
        return;
    }
    convert(num / base, base);
    int remainder = num % base;
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + remainder - 10);
    }
}

int main() {
    int d, h;
    scanf("%d%d", &d, &h);
    if (d == 0) {
        printf("0");
    } else {
        convert(d, h);
    }
    return 0;
}