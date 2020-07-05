#include <stdlib.h>
#include <stdio.h>

int N, K, R, T;
int w[52];
int v[52];
int dp_w[102][52];
int dp_v[102][52];

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d %d ", &v[i], &w[i]);
		}
		scanf("%d ", &K);
		scanf("%d ", &R);
		// printf("K = %d, N = %d\n", K, N);
		// printf("A\n");
		for (int k = 1; k <= K; k++) {
			for (int n = 1; n <= N; n++) {
				if (w[n] > k) {
					dp_w[k][n] = dp_w[k][n-1];
					dp_v[k][n] = dp_v[k][n-1];
				} else if (dp_w[k][n-1] + w[n] <= k) {
					dp_w[k][n] = dp_w[k][n-1] + w[n];
					dp_v[k][n] = dp_v[k][n-1] + v[n];	
				} else if (dp_v[k][n-1] >= dp_v[k-w[n]][n-1] + v[n]) {
					dp_w[k][n] = dp_w[k][n-1];
					dp_v[k][n] = dp_v[k][n-1];
				} else {
					dp_w[k][n] = dp_w[k-w[n]][n-1] + w[n];
					dp_v[k][n] = dp_v[k-w[n]][n-1] + v[n];
				}
			}
		}
		if (dp_v[K][N] >= R) {
			printf("Missao completada com sucesso\n");
		} else {
			printf("Falha na missao\n");
		}
	}
	return 0;
}