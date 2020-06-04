#include <stdlib.h>
#include <stdio.h>

int arr[1001][1001];
int col[1001];
int lin[1001];
int N, M, C;

int distance(int a, int b) {
	if (b == -1) {
		return C;
	}
	return a - b - 1;
}

int eval() {
	for (int i = 0; i < M; i++) {
		if (col[i] != 0) {
			if (i > 0) {
				if (col[i-1] != 0) {
					return 0;
				}
			}
			if (i < M-1) {
				if (col[i+1] != 0) {
					return 0;
				}
			}
			
			int lastOne = -1;
			int lastTwo = -1;
			for (int j = 0; j < N; j++) {
				if (arr[j][i] == 1) {
					if (distance(j, lastOne) < C) {
						return 0;
					}
					lastOne = j;
				} else if (arr[i][j] == 2) {
					if (distance(j, lastTwo) < C) {
						return 0;
					}
					lastTwo = j;
				}
			}
		}
	}

	return 1;
}

int main() {
	scanf("%d %d %d ", &N, &M, &C);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}

	for (int j = 0; j < M; j++) {
		int s = 0;
		for (int i = 0; i < N; i++) {
			s += arr[i][j];
		}
		col[j] = s;
	}

	if (eval()) {
		printf("S\n");
	} else {
		printf("N\n");
	}


}