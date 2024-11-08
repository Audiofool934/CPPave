#include <stdio.h>
#include <limits.h>

// Function to find the maximum time of two
int max(int a, int b) {
    return (a > b) ? a : b; 
}

// Function to find the minimum time required to process all materials
int minTime(int k, int n, int m, int U[], int V[]) {
    int max_processing_time = 0;  // Holds the longest processing time of any material
    int total_time = 0;           // Total time needed

    // Iterate through all materials
    for (int i = 0; i < k; i++) {
        // Determine maximum processing time across all machines for this material
        int current_max = max(U[i], V[i]); 
        max_processing_time = max(max_processing_time, current_max);

        // Add the processing time to the total
        total_time += current_max; 
    }

    // Consider maximum machine load as a lower bound for total time
    return max(total_time, max_processing_time);
}

int main() {
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);

    int U[n], V[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &U[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &V[i]);
    }

    int min_time = minTime(k, n, m, U, V);
    printf("%d\n", min_time);

    return 0;
}
