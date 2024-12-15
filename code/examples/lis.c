#include <stdio.h>
#define MAXN 1000 // Maximum array size

// Recursive function to find the LIS with 'prev' as the last included element
int LISBigger(int prev, int A[], int n) {
    if (n == 0) return 0;

    if (A[0] <= prev) {
        // Skip the current element if it's not greater than 'prev'
        return LISBigger(prev, A + 1, n - 1);
    } else {
        // two cases: skipping or taking the current element
        int skip = LISBigger(prev, A + 1, n - 1);
        int take = LISBigger(A[0], A + 1, n - 1) + 1;
        return (skip > take) ? skip : take; // max(skip, take)
    }
}

int main() {
    int n, A[MAXN];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Call the LISBigger function with 'prev' initialized to a very small value
    int result = LISBigger(-1000000000, A, n);

    printf("The length of the Longest Increasing Subsequence is: %d\n", result);

    return 0;
}