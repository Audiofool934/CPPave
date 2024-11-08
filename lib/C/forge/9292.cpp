#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);

    int Ui[n], Vi[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &Ui[i]);
    }
    for (int j = 0; j < m; j++) {
        scanf("%d", &Vi[j]);
    }

    qsort(Ui, n, sizeof(int), compare);
    qsort(Vi, m, sizeof(int), compare);

    int step1[n], step2[m];
    for (int i = 0; i < n; i++) {
        step1[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        step2[i] = 0;
    }

    int uiIndex = 0, viIndex = 0;
    for (int i = 0; i < k; i++) {
        step1[uiIndex] += Ui[uiIndex];
        step2[viIndex] = (step2[viIndex] > step1[uiIndex] ? step2[viIndex] : step1[uiIndex]) + Vi[viIndex];

        uiIndex = (uiIndex + 1) % n;
        viIndex = (viIndex + 1) % m;
    }

    int maxTime = 0;
    for (int i = 0; i < m; i++) {
        if (step2[i] > maxTime) {
            maxTime = step2[i];
        }
    }

    printf("%d\n", maxTime);
    return 0;
}
