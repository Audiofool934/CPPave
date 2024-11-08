#include <stdio.h>
int step=0;
void hanoi(int n, char a, char b, char c) {
    //printf("%d\n",n);
    if (n == 1) {
        step++;
        printf("[step %d]	 move plate %d#	 from %c to %c\n", step, n, a, c);
        return;
    }

    hanoi(n-1, a, c, b);
    step++;
    printf("[step %d]	 move plate %d#	 from %c to %c\n", step, n, a, c);
    hanoi(n-1, b, a, c);
}

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
    printf("%d\n", step);
    return 0;
}
