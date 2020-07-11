#include <stdlib.h>
#include <stdio.h>

int T, N;
int DP[100];
int b[100];
int pointer;

int fib(int n) {
	if (DP[n] != 0) {
		return DP[n];
	}
	DP[n] = fib(n-1) + fib(n-2);
	return DP[n];
}

void init() {
	DP[1] = 1;
	DP[2] = 2;
	fib(30);
}

int main() {
	init();
	
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		int f = 1;
		int v;
		for (int i = 25; i >= 1; i--) {
			v = fib(i);
			if (v <= N) {
				N -= v;
				b[i] = 1;
				if (f) {
					f = 0;
					pointer = i;
				}
			} else {
				b[i] = 0;
			}
		}
		for (int i = pointer; i > 1; i--) {
			N += b[i]*fib(i-1);
		}
		printf("%d\n", N);
	}
	return 0;
}