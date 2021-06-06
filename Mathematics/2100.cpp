#include <stdlib.h>
#include <stdio.h>

#define MOD 1300031
#define NIL -1
#define LLD long long int

int T, N, M;
LLD dp[4009][2009];

LLD search(int n, int m) {
	if (!m) {
		return 1;
	} else if (!n) {
		return 0;
	} else if (dp[n][m] != NIL) {
		return dp[n][m];
	}

	LLD v;
	if (n == m*2) {
		v = (2*m * search(n-2, m-1)) % MOD;
	} else if (n >= 2 && m >= 1) {
		LLD m1 = (2*m * search(n-2, m-1)) % MOD; 
		LLD m2 = search(n-1, m) % MOD;
		v = (m1 + m2) % MOD;
	} else {
		v = search(n-1, m) % MOD;
	}
	dp[n][m] = v;
	return v;
}

int main() {
	for (int i = 0; i < 4009; i++) {
		for (int j = 0; j < 2009; j++) {
			dp[i][j] = NIL;
		}
	}

	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ", &N, &M);
		LLD res = search(N, M);
		printf("%Ld\n", res);
	}
	return 0;
}