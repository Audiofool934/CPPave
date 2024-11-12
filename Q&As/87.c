#include <stdio.h>
#include <math.h>

struct pix {
    int Ri;
    int Gi;
    int Bi;
};

int main(void) {
    int n, m, hi = 0;
    scanf("%d%d", &n, &m);
    getchar();
    struct pix pixs[n + 2][m + 2][1000]; // 这里其实浪费了很多空间，实际上两个二维数组就够了

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            getchar();
            getchar();
            scanf("%d", &pixs[i][l][1].Ri);
            getchar();
            getchar();
            scanf("%d", &pixs[i][l][1].Gi);
            getchar();
            getchar();
            scanf("%d", &pixs[i][l][1].Bi);
        }
        getchar();
    }

    while (1) {
        int zero = 0;
        hi++;
        for (int i = 1; i <= n; i++) {
            for (int l = 1; l <= m; l++) {
                pixs[i][l][hi + 1].Ri = pixs[i][l][hi].Ri;
                pixs[i][l][hi + 1].Gi = pixs[i][l][hi].Gi;
                pixs[i][l][hi + 1].Bi = pixs[i][l][hi].Bi;
                if (pixs[i][l][hi].Ri == 0 && pixs[i][l][hi].Gi == 0 && pixs[i][l][hi].Bi == 0) {
                    zero++;
                    int sumR = 0, sumG = 0, sumB = 0, sum = 0;
                    if (pixs[i - 1][l][hi].Ri != 0 || pixs[i - 1][l][hi].Gi != 0 || pixs[i - 1][l][hi].Bi != 0) sum += 1;
                    if (pixs[i + 1][l][hi].Ri != 0 || pixs[i + 1][l][hi].Gi != 0 || pixs[i + 1][l][hi].Bi != 0) sum += 1;
                    if (pixs[i][l + 1][hi].Ri != 0 || pixs[i][l + 1][hi].Gi != 0 || pixs[i][l + 1][hi].Bi != 0) sum += 1;
                    if (pixs[i][l - 1][hi].Ri != 0 || pixs[i][l - 1][hi].Gi != 0 || pixs[i][l - 1][hi].Bi != 0) sum += 1;

                    sumR += pixs[i - 1][l][hi].Ri + pixs[i + 1][l][hi].Ri + pixs[i][l + 1][hi].Ri + pixs[i][l - 1][hi].Ri;
                    sumG += pixs[i - 1][l][hi].Gi + pixs[i + 1][l][hi].Gi + pixs[i][l + 1][hi].Gi + pixs[i][l - 1][hi].Gi;
                    sumB += pixs[i - 1][l][hi].Bi + pixs[i + 1][l][hi].Bi + pixs[i][l + 1][hi].Bi + pixs[i][l - 1][hi].Bi;

                    if (sumR == 0 && sumG == 0 && sumB == 0) {
                        pixs[i][l][hi + 1].Ri = 0;
                        pixs[i][l][hi + 1].Gi = 0;
                        pixs[i][l][hi + 1].Bi = 0;
                    } else {
                        pixs[i][l][hi + 1].Ri = ceil((double)sumR / (double)sum);
                        pixs[i][l][hi + 1].Gi = ceil((double)sumG / (double)sum);
                        pixs[i][l][hi + 1].Bi = ceil((double)sumB / (double)sum);
                    }
                }
            }
        }
        if (zero == m * n || zero == 0) break; // 注意全是坏点的边界情况
    }

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            printf("R %d G %d B %d ", pixs[i][l][hi].Ri, pixs[i][l][hi].Gi, pixs[i][l][hi].Bi);
        }
        printf("\n");
    }
}