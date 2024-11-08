#include <stdio.h>
#include <iostream>
using namespace std;

struct aa {
	int s;
	int wk;
	int tm;
};

int main() {
	struct aa a[50];
	for (int i = 1; i <= 49; i++) {
		a[i].s = 0;
		a[i].wk=(i-1)/7+1;
		a[i].tm=i-7*((i-1)/7+1);
		/*if (i <= 7) {
			a[i].wk =  1;
			a[i].tm = i ;
		}
		if (7 < i && i <= 14) {
			a[i].wk =  2;
			a[i].tm = i - 7;
		}
		if (14 < i && i <= 21) {
			a[i].wk = 3;
			a[i].tm = i - 14;
		}
		if (21 < i && i <= 28) {
			a[i].wk =  4;
			a[i].tm = i - 21;
		}
		if (28 < i && i <= 35) {
			a[i].wk =  5;
			a[i].tm = i - 28;
		}
		if (35 < i && i <= 42) {
			a[i].wk =  6;
			a[i].tm = i - 35;
		}
		if (i > 42) {
			a[i].wk =  7;
			a[i].tm = i - 42;
		}*/
	}
	int n, nn, kk, tmp, week, time;
	scanf("%d %d", &n, &kk);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &tmp, &nn);
		for (int j = 1; j <= nn; j++) {
			scanf("%d.%d", &week, &time);
			a[7 * (week - 1) + time].s++;
		}
	}
	for (int j = 1; j <= 49; j++) {
		for (int k = 1; k <= 49 - j; k++) {
			if (a[k].s > a[k + 1].s) {
				swap(a[k], a[k + 1]);
			}
		}
	}
	for (int i = 1; i <= kk; i++) {
		printf("%d.%d %d\n", a[i].wk, a[i].tm, a[i].s);
	}
	return 0;
}