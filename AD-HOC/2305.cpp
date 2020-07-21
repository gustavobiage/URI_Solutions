#include <stdlib.h>
#include <stdio.h>

int L, C, N, M;
int DP[1009][1009];
int arr[1009][1009];
int max;

int main() {
	scanf("%d %d %d %d ", &L, &C, &M, &N);
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}

	for (int i = 1; i <= L; i++) {
		int sum = 0;
		for (int j = C; j; j--) {
			sum += arr[i][j];
			if (C-j >= N) {
				sum -= arr[i][j+N];
			}
			DP[i][j] = sum;
		}
	}
	max = -1;
	for (int i = 1; i <= C-N+1; i++) {
		int sum = 0;
		for (int j = L; j; j--) {
			sum += DP[j][i];
			if (L-j >= M) {
				sum -= DP[j+M][i];
			}
			if (sum > max) {
				max = sum;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}