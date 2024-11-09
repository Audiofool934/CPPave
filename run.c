#include <stdio.h>
#include<math.h>

int solve(int n, int m) {
    int cnt = 0;
    while (1) {
        cnt++;
        if ((cnt == m + 1) && (n % m == 0)) {
            return 1;
        }
        if (n < m || n % m != 1 || cnt > m + 1) {
            return 0;
        }
        n = n - ( n / m ) - 1;
    }
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        int cn = 1;
        for (int i = sqrt(n-1); i >= 1; i--) {
            if (solve(n, i)) {
                printf("%d\n", i);
                cn = 0;
                break;
            }
        }
        if (cn) {
            printf("no solution\n");
        }
    }
    return 0;
}
