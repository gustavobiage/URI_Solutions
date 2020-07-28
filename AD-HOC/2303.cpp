#include <stdlib.h>
#include <stdio.h>

int L, C, M, N;
int cnt[1000][1000];
int v, max;

int main() {
	scanf("%d %d %d %d ", &L, &C, &M, &N);
	int a, b;
	a = b = 0;
	for (int i = 0; i < L; i++) {
		if (i && i % M == 0) {
			a++;
		}
		b = 0;
		for (int j = 0; j < C; j++) {
			if (j && j % N == 0) {
				b++;
			}
			scanf("%d ", &v);
			cnt[a][b] += v;
		}
	}
	M = L / M;
	N = C / N;
	max = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (cnt[i][j] > max) {
				max = cnt[i][j];
			}
		}
	}
	printf("%d\n", max);
	return 0;
}