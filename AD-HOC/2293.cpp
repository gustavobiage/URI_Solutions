#include <stdlib.h>
#include <stdio.h>

#define C 0
#define L 1

int colSum[101];
int lineSum[101];
int arr[101][101];
int N, M;
int index, max, type;
int c;

int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d ", &arr[i][j]);
			colSum[j] += arr[i][j];
			lineSum[i] += arr[i][j];
		}
	}
	c = 0;
	max = -1;
	for (int i = 0; i < N; i++) {
		if (lineSum[i] > max) {
			max = lineSum[i];
			index = i;
			type = L;
		}
	}
	for (int i = 0; i < M; i++) {
		if (colSum[i] > max) {
			max = colSum[i];
			index = i;
			type = C;
		}
	}
	printf("%d\n", max);
	return 0;
}