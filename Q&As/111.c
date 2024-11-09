#include <stdio.h>
#include <math.h>

int diedai(int x, int m) {
	int count = 0;
	while (x % m != 0) {
		if ((x - 1) % m == 0) {
			x = ((x - 1) / m) * (m - 1);
			count++;
		} else {
			return 1;
		}
	}
	if (count == m) {
		return 0;
	}
	return 1;
}

int main() {
	int i;
	int co[20], value = 0, count0 = 0;
	for (i = 0; i < 20; i++) {
		scanf("%d", &co[i]);
		if (co[i] == 0) break;
		count0++;
	}
	for (i = 0; i < count0; i++) {
		value = 0;
		for (int m = co[i] - 1; m > 0; m--) {
			// value = 0;
			if (diedai(co[i], m) == 0) {
				printf("%d\n", m);
				value = 1;
				break;
			}
		}
		if (value == 0) {
			printf("no solution\n");
		}
	}
	return 0;
}
