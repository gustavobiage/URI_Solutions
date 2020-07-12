#include <stdlib.h>
#include <stdio.h>

int N, M;
int arr[1009][1009];


int test(int x, int y) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!i && !j || (x+i < 1 || x+i > N || y+j < 1 || y+j > M)) {
				continue;
			}
			if (arr[x][y] <= arr[x+i][y+j]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	while (scanf("%d %d ", &N, &M) != EOF) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d ", &arr[i][j]);
			}
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (test(i, j)) {
					printf("%d %d\n", i, j);
					cnt++;
				}
			}
		}
		if (!cnt) {
			printf("-1\n");
		}
		printf("\n");
	}
	return 0;
}