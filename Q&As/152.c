#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int trans(int x, int t) {
    int y = 0, x0, count = 0;
    while (x != 0) {
        x0 = x % 10;
        if (x0 >= t) { // 数字要<进制
            return -1;
        }
        y += x0 * pow(t, count);
        count++;
        x /= 10;
    }
    return y;
}

bool mult(int t, int x1, int x2, int y) {
    x1 = trans(x1, t);
    x2 = trans(x2, t);
    y = trans(y, t);

    if (x1 == -1 || x2 == -1 || y == -1) // 数字要<=进制
        return false;

    if (x1 * x2 == y) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int T, i;
    int a[100][3];
    int t[100];
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    for (i = 0; i < T; i++) {
        bool flag = false;
        for (int j = 2; j <= 16; j++) {
            if (mult(j, a[i][0], a[i][1], a[i][2])) {
                t[i] = j;
                flag = true;
                break;
            }
        }
        if (!flag) {
            t[i] = 0;
        }
    }
    for (i = 0; i < T; i++) {
        printf("%d\n", t[i]);
    }
    return 0;
}
