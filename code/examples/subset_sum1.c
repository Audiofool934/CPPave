#include <stdio.h>
#include <stdbool.h>

bool subsetSum(int X[], int n, int T) {
    // Base cases
    if (T == 0) return true;
    if (T < 0 || n == 0) return false;

    int x = X[n-1]; // 每次任意选择元素 x 遍历 X 即可，这里选择最后一个元素

    bool with = subsetSum(X, n-1, T - x); // x is included
    bool wout = subsetSum(X, n-1, T); // x is excluded

    return with || wout;
}

int main() {
    int n, T;
    printf("Enter the number of elements in the set X: ");
    scanf("%d", &n);

    int X[n];
    printf("Enter the elements of X:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    printf("Enter the target T: ");
    scanf("%d", &T);

    if (subsetSum(X, n, T)) {
        printf("Yes, there is a subset that sums up to %d.\n", T);
    } else {
        printf("No, there isn't any subset that sums up to %d.\n", T);
    }

    return 0;
}