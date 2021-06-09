#include <stdlib.h>
#include <stdio.h>

int G, g;
int P, W;

int w[109];
int v[109];

int mw[109][1009];
int mv[109][1009];

int main() {
	scanf("%d ", &G);
	g = G;
	while (g--) {
		scanf("%d %d ", &P, &W);
		int pointer = 0;
		for (int i = 1; i <= P; i++) {
			scanf("%d %d ", &v[i], &w[i]);
		}
		for (int c = 1; c <= W; c++) {
			for (int i = 1; i <= P; i++) {
				if (w[i] > c) {
					mw[i][c] = mw[i-1][c];
					mv[i][c] = mv[i-1][c];
				} else if (mw[i-1][c] + w[i] <= c) {
					mw[i][c] = mw[i-1][c] + w[i];
					mv[i][c] = mv[i-1][c] + v[i];
				} else if (mv[i-1][c] >= mv[i-1][c-w[i]] + v[i]) {
					mw[i][c] = mw[i-1][c];
					mv[i][c] = mv[i-1][c];
				} else {
					mw[i][c] = mw[i-1][c-w[i]] + w[i];
					mv[i][c] = mv[i-1][c-w[i]] + v[i];
				}
			}
		}
		printf("Galho %d:\n", G - g);
		printf("Numero total de enfeites: %d\n", mv[P][W]);
		printf("\n");
	}
	return 0;
}