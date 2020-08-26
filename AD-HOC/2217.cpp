#include <stdlib.h>
#include <stdio.h>

int t, v;

int fast_sqr(int n, int m, int mod) {
	if (!m) {
		return 1;
	} else if (m == 1) {
		return n % mod;
	}

	int newm = m / 2;
	int x = fast_sqr(n, newm, mod);
	x = (x * x) % mod;
	if (m % 2) {
		x = (x * n) % mod;
	}
	return x;
}

int main() {
	scanf("%d ", &t);
	while (t--) {
		scanf("%d ", &v);
		printf("%d\n", fast_sqr(9, v, 10));
	}
	return 0;
}