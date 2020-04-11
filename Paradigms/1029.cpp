#include <stdlib.h>
#include <stdio.h>

int DP[50];
int R[50];

int fib(int n) {
	if (n <= 1) {
		DP[n] = n;
		return 1;
	}

	if (R[n] == 0) {
		R[n] = fib(n-1) + fib(n-2) + 1;
		DP[n] = DP[n-1] + DP[n-2];
	}

	return R[n];
}

int T;
int X;
int r, v;
int main() {

	scanf("%d ", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d ", &X);
		r = fib(X);
		v = DP[X];
		printf("fib(%d) = %d calls = %d\n", X, r - 1, v);
	}
}