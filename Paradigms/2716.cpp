#include <stdlib.h>
#include <stdio.h>

int DP[300009][159];
int arr[159];
int N, total;
int min;

int main() {
	while (scanf("%d ", &N) != EOF) {
		total = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d ", &arr[i]);
			total += arr[i];
		}
		for (int i = 1; i <= total/2; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[j] > i || DP[i][j-1] > DP[i-arr[j]][j-1] + arr[j]) {
					DP[i][j] = DP[i][j-1];
				} else {
					DP[i][j] = DP[i-arr[j]][j-1] + arr[j];
				}
			}
		}
		min = (total - DP[total/2][N]) - DP[total/2][N];
		printf("%d\n", min);
	}
	return 0;
}