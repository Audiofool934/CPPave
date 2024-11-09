#include <iostream>
#include <cstdio>
using namespace std;

int n;
int guess[15][7];

int compare(int a[], int b[]) {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] != 0 && b[i] != 0) {
            cnt += min(a[i], b[i]);
        }
    }
    return cnt;
}

int check(int ans[]) {
    int base1[10] = {0};
    for (int i = 0; i < 4; i++) {
        base1[ans[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        int base2[10] = {0};
        for (int j = 1; j <= 4; j++) {
            base2[guess[i][j]]++;
        }
        if (compare(base1, base2) != guess[i][5]) return 0;
    }

    for (int i = 1; i <= n; i++) {
        int t6 = 0;
        for (int j = 1; j <= 4; j++) {
            if (ans[j - 1] == guess[i][j]) {
                t6++;
            }
        }
        if (t6 != guess[i][6]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= 4; j++) {
            guess[i][j] = getchar() - '0';
        }
        scanf("%d%d", &guess[i][5], &guess[i][6]);
    }

    int mtd = 0;
    int output[4];
    int ans[4];

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    ans[0] = i; ans[1] = j; ans[2] = k; ans[3] = l;
                    if (check(ans)) {
                        mtd++;
                        output[0] = i; output[1] = j; output[2] = k; output[3] = l;
                    }
                    if (mtd >= 2) break;
                }
                if (mtd >= 2) break;
            }
            if (mtd >= 2) break;
        }
        if (mtd >= 2) break;
    }

    if (mtd == 1) {
        printf("%d%d%d%d\n", output[0], output[1], output[2], output[3]);
    } else {
        printf("Not sure");
    }

    return 0;
}