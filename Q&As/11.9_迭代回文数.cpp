#include <stdio.h>
#include <algorithm>
using namespace std;

struct number {
	long long int origin;
	int times;
	long long int huiwen;
};

long long int diedai(long long int a) {
	long long int result = 0;
	while (a != 0) {
		result = result * 10 + a % 10;
		a = a / 10;
	}
	return result;
}

bool cmp(number a, number b) {
	if (a.times > b.times) {
		return true;
	} else if (a.times == b.times && a.huiwen < b.huiwen) {
		return true;
	} else if (a.times == b.times && a.huiwen == b.huiwen && a.origin < b.origin) {
		return true;
	} else {
		return false;
	}
}

int main(void) {
	struct number num[10];
	for (int i = 0; i < 10; i++) {
		scanf("%lld", &num[i].origin);
		num[i].huiwen = num[i].origin;
		int t = 0;
		while (diedai(num[i].huiwen) != num[i].huiwen) {
			t += 1;
			num[i].huiwen = diedai(num[i].huiwen) + num[i].huiwen;
		}
		num[i].times = t;
	}
	sort(num, num + 10, cmp);
	for (int i = 0; i < 10; i++) {
		printf("%lld %d %lld\n", num[i].origin, num[i].times, num[i].huiwen);
	}

	return 0;
}
