#include <stdio.h>

int josephus(int n, int k) {
    int result = 0;  // The position of the last remaining person
    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }
    return result + 1;  // Adjusting the result to 1-based index
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", josephus(n, k));
    return 0;
}
