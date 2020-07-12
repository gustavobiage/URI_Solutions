#include <stdlib.h>
#include <stdio.h>

int T;
int N, M;
int arr[30];
int DP[1000001][30];

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ", &N, &M);
		for (int i = 1; i <= N; i++) {
			scanf("%d ", &arr[i]);
		}
		DP[0][0] = 0;
		for (int i = 1; i <= M; i++) {
			DP[i][0] = 1000009;
			for (int j = 1; j <= N; j++) {
				if (arr[j] > i) {
					DP[i][j] = DP[i][j-1];
				} else if (DP[i-arr[j]][j] + 1 < DP[i][j-1]) {
					DP[i][j] = DP[i-arr[j]][j] + 1;
				} else {
					DP[i][j] = DP[i][j-1];
				}
			}
		}
		printf("%d\n", DP[M][N]);
	}
	return 0;
}