#include <stdio.h>
#include <stdbool.h>

#define MAXN 50

// Function to construct the subset
bool constructSubset(int X[], int i, int T, int result[], int *resultSize) {
    if (T == 0) {
        // Found a subset that sums to T
        *resultSize = 0; // Empty subset
        return true;
    }
    if (T < 0 || i < 0) {
        // No subset found
        return false;
    }

    // Try without including X[i]
    if (constructSubset(X, i - 1, T, result, resultSize)) {
        return true;
    }

    // Try including X[i]
    if (constructSubset(X, i - 1, T - X[i], result, resultSize)) {
        // Add X[i] to the result subset
        result[*resultSize] = X[i];
        (*resultSize)++;
        return true;
    }

    // No subset found
    return false;
}

int main() {
    int n, T;
    printf("Enter the number of elements in the set X: ");
    scanf("%d", &n);

    int X[MAXN];
    printf("Enter the elements of X:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    printf("Enter the target T: ");
    scanf("%d", &T);

    int result[MAXN];
    int resultSize;

    if (constructSubset(X, n - 1, T, result, &resultSize)) {
        printf("Subset that sums up to %d: ", T);
        for (int i = 0; i < resultSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("No subset found that sums up to %d.\n", T);
    }

    return 0;
}