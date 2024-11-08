#include <stdio.h>

int main() 
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n/2+1 ; i++) {//n/2+1
		for (int j = i; j <= n/2 + 1; j++) {//n/2+1
			if ((i + j) * (j - i + 1) / 2 == n) {
				printf("[%d, %d]\n", i, j);
				break;
			}
			if ((i + j) * (j - i + 1) / 2 > n) break;
		}
	}
	return 0;
}