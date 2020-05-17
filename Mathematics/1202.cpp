#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T;
int DP[100000];
int MOD = 1500;
char line[2000000];
int s, value, len;

int fib(int n) {
	if (n <= 2) {
		DP[n] = 1;
		return 1;
	}

	if (DP[n] != 0) {
		return DP[n];
	}

	DP[n] = (fib(n-2) + fib(n-1)) % 1000;
	return DP[n];
}

int main() {

	scanf("%d ", &T);
	fib(MOD);
	while (T) {
		scanf(" %s ", line);
		len = strlen(line);
		s = 1;
		value = 0;
		for (int i = len-1; i >= 0; i--) {
			if (line[i] == '1') {
				value += s;
				value = value % MOD;
			}
			s = (s*2) % MOD;
		}

		if (DP[value] < 10) {
			printf("00%d\n", DP[value]);
		} else if (DP[value] < 100) {
			printf("0%d\n", DP[value]);
		} else {
			printf("%d\n", DP[value]);
		}

		T--;
	}
	return 0;
}

//Reference:
// https://en.wikipedia.org/wiki/Pisano_period