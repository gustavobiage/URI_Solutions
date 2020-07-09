#include <stdlib.h>
#include <stdio.h>

int N, C;
int DP[101][1001];
int v[1001];
int w[1001];
int c;

int main() {
	c = 0;
	while (1) {
		scanf("%d %d ", &N, &C);
		if (!N && !C) {
			break;
		}
		c++;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d ", &w[i], &v[i]);
		}
		DP[0][0] = 0;
		for (int i = 1; i <= C; i++) {
			for (int j = 1; j <= N; j++) {
				if (w[j] > i) {
					DP[i][j] = DP[i][j-1];
				} else if (DP[i][j-1] >= DP[i-w[j]][j-1] + v[j]) {
					DP[i][j] = DP[i][j-1];
				} else {
					DP[i][j] = DP[i-w[j]][j-1] + v[j];
				}
			}
		}
		printf("Caso %d: %d\n", c, DP[C][N]);
	}

	return 0;
}