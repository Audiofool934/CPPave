#include <stdio.h>
#include <stdbool.h>

#define MAXN 50  // Adjust as needed

int Q[MAXN+1]; // Q[r] represents the column position of the queen in row r
int n;

void printSolution(int Q[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

void PlaceQueens(int Q[], int r, int n) {
    if (r == n + 1) {
        // All queens are placed, print the solution
        printSolution(Q, n);
    } else {
        for (int j = 1; j <= n; j++) {
            bool legal = true;
            // Check all previously placed queens
            for (int i = 1; i < r; i++) {
                // Check if placing a queen at (r,j) conflicts with (i, Q[i])
                // Conditions:
                // 1. Same column: Q[i] == j
                // 2. Same major diagonal: Q[i] == j + r - i
                // 3. Same minor diagonal: Q[i] == j - r + i
                if (Q[i] == j || Q[i] == j + r - i || Q[i] == j - r + i) {
                    legal = false;
                    break;
                }
            }
            if (legal) {
                Q[r] = j;
                PlaceQueens(Q, r + 1, n);
            }
        }
    }
}

int main() {
    printf("Enter the value of n: ");
    scanf("%d", &n);

    PlaceQueens(Q, 1, n);

    return 0;
}