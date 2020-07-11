#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int R, K;
int cnt[101];
int DP[10001][101];
int a, b;

int main() {
	while (scanf("%d %d ", &R, &K) != EOF) {
		memset(cnt, 0, sizeof(int)*(R+1));
		for (int i = 0; i < K; i++) {
			scanf("%d %d ", &a, &b);
			cnt[a]++;
			cnt[b]++;
		}
		DP[0][0] = 0;
		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= R; j++) {
				if (cnt[j] > i) {
					DP[i][j] = DP[i][j-1];
				} else if (DP[i][j-1] > DP[i-cnt[j]][j-1] + cnt[j]) {
					DP[i][j] = DP[i][j-1];
				} else {
					DP[i][j] = DP[i-cnt[j]][j-1] + cnt[j];
 				}
			}
		}
		if (DP[K][R] == K) {
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}