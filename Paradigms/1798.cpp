#include <stdlib.h>
#include <stdio.h>

int N;
int T;
int DP[2001][1001];
int size[1001];
int value[1001];

int main() {
	scanf("%d %d ", &N, &T);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d ", &size[i], &value[i]);
	}
	DP[0][0] = 0;
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= N; j++) {
			if (size[j] > i) {
				DP[i][j] = DP[i][j-1];
			} else if (DP[i][j-1] >= DP[i-size[j]][j] + value[j]) {
				DP[i][j] = DP[i][j-1];
			} else {
				DP[i][j] = DP[i-size[j]][j] + value[j];
			}
		}
	}
	printf("%d\n", DP[T][N]);
	return 0;
}