#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort_descending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int find_max_perimeter(int arr[], int n) {
    for (int i = 0; i < n - 2; i++) {
        if (arr[i] < arr[i + 1] + arr[i + 2]) {
            return arr[i] + arr[i + 1] + arr[i + 2];
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort_descending(a, n);
    int max_perimeter = find_max_perimeter(a, n);
    printf("%d\n", max_perimeter);

    return 0;
}