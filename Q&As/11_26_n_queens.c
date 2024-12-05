#include <stdio.h>

int c[13][13] = {0};
int col[13] = {0};
int diag1[26] = {0};
int diag2[26] = {0};

void Try(int i, int n, int *count) {
    if (i == n) {
        (*count)++;
        return;
    } else {
        for (int j = 0; j < n; j++) {
            if (col[j] == 0 && diag1[i + j] == 0 && diag2[i - j + n] == 0) {
                c[i][j] = 1;
                col[j] = 1;
                diag1[i + j] = 1;
                diag2[i - j + n] = 1;
                Try(i + 1, n, count);
                c[i][j] = 0;
                col[j] = 0;
                diag1[i + j] = 0;
                diag2[i - j + n] = 0;
            }
        }
    }
}

int main() {
    int count = 0;
    int n;
    scanf("%d", &n);
    Try(0, n, &count);
    printf("%d", count);
    return 0;
}
