#include <stdlib.h>
#include <stdio.h>

int N, P;
int NUMBER[35], AMOUNT[35];
int DP[35][35];
int V[35][35];

int main() {

	while (1) {
		scanf("%d ", &N);

		if (N == 0) {
			break;
		}

		scanf("%d ", &P);

		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &NUMBER[i+1], &AMOUNT[i+1]);
			DP[0][i] = 0;
		}

		DP[0][N] = 0;

		for (int j = 0; j <= P; j++) {
			DP[j][0] = 0;
		}

		for (int i = 0; i <= P; i++) {
			for (int j = 1; j <= N; j++) {
				if (AMOUNT[j] > i) {
					DP[i][j] = DP[i][j-1];
					V[i][j] = V[i][j-1];
					continue;
				}

				if (DP[i][j-1] + AMOUNT[j] <= i) {
					DP[i][j] = DP[i][j-1] + AMOUNT[j];
					V[i][j] = V[i][j-1] + NUMBER[j];
				} else {
					if (V[i-AMOUNT[j]][j-1] + NUMBER[j] > V[i][j-1]) {
						DP[i][j] = DP[i-AMOUNT[j]][j-1] + AMOUNT[j];
						V[i][j] = V[i-AMOUNT[j]][j-1] + NUMBER[j]; 
					} else {
						DP[i][j] = DP[i][j-1];
						V[i][j] = V[i][j-1];
					}
				}
			}
		}

		printf("%d min.\n", V[P][N]);
	}
	return 0;
}