#include <stdlib.h>
#include <stdio.h>

int G, P, W;
int w[102];
int v[102];
int c;

int w_dp[1002][102];
int v_dp[1002][102];

int main() {
	c = 0;
	scanf("%d ", &G);
	while (G--) {
		c++;
		scanf("%d %d ", &P, &W);
		for (int i = 1; i <= P; i++) {
			scanf("%d %d ", &v[i], &w[i]);
		}

		for (int i = 1; i <= W; i++) {
			for (int j = 1; j <= P; j++) {
				if (w[j] > i) {
					w_dp[i][j] = w_dp[i][j-1];
					v_dp[i][j] = v_dp[i][j-1];
				} else if (w_dp[i][j-1] + w[j] <= i) {
					w_dp[i][j] = w_dp[i][j-1] + w[j];
					v_dp[i][j] = v_dp[i][j-1] + v[j];
				} else if (v_dp[i][j-1] >= v_dp[i-w[j]][j-1] + v[j]) {
					w_dp[i][j] = w_dp[i][j-1];
					v_dp[i][j] = v_dp[i][j-1];	
				} else {
					w_dp[i][j] = w_dp[i-w[j]][j-1] + w[j];
					v_dp[i][j] = v_dp[i-w[j]][j-1] + v[j];
				}
			}
		}
		printf("Galho %d:\n", c);
		printf("Numero total de enfeites: %d\n", v_dp[W][P]);
		printf("\n");
	}
	return 0;
}