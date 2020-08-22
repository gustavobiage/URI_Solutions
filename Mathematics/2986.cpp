#include <stdlib.h>
#include <stdio.h>

#define MOD 1000000007

int dp[1000009];
char visited[1000009];

int find(int n) {
	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	}
	if (visited[n]) {
		return dp[n];
	}
	dp[n] = ((find(n-1) + find(n-2)) % MOD + find(n-3)) % MOD;
	visited[n] = 1;
	return dp[n];
}

int main() {
	int n;
	scanf("%d ", &n);
	printf("%d\n", find(n+1));
	return 0;
}