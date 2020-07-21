#include <stdlib.h>
#include <stdio.h>

int C;
int N, M, P;
char arr[1001][1001];
int x, y;

int main() {
	scanf("%d ", &C);
	while (C--) {
		scanf("%d %d %d ", &N, &M, &P);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%c ", &arr[i][j]);
			}
			arr[i][M+1] = '.';
		}
		for (int j = 1; j <= M; j++) {
			arr[N+1][j] = '.';
		}
		for (int i = 0; i < P; i++) {
			scanf("%d %d ", &x, &y);
			int cnt = 0;
			for (int dx = -1; dx <= 1; dx++) {
				for (int dy = -1; dy <= 1; dy++) {
					if (!dx && !dy) {
						continue;
					}
					cnt += arr[x+dx][y+dy] == 'T';
				}
			}
			if (cnt < 5) {
				printf("GG IZI\n");
			} else {
				printf("GRRR\n");
			}
		}
	}
	return 0;
}