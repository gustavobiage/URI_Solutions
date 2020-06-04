#include <stdlib.h>
#include <stdio.h>

int C, F;

int N[51];
int D[51];
int peso[1001][51];
int valor[1001][51];
int c;

int main() {
	c = 0;
	while (1) {
		scanf("%d %d ", &C, &F);
		if (!C && !F) {
			break;
		}
		c++;
		for (int i = 1; i <= F; i++) {
			scanf("%d %d ", &N[i], &D[i]);
		}
		peso[0][0] = 0;
		for (int c = 1; c <= C; c++) {
			for (int i = 1; i <= F; i++) {
				if (N[i] > c) {
					peso[c][i] = peso[c][i-1];
					valor[c][i] = valor[c][i-1];
					continue;
				}

				if (peso[c][i-1] + N[i] <= c) {
					peso[c][i] = peso[c][i-1] + N[i];
					valor[c][i] = valor[c][i-1] + D[i];
				} else {
					if (valor[c][i-1] >= valor[c-N[i]][i-1] + D[i]) {
						valor[c][i] = valor[c][i-1];
						peso[c][i] = peso[c][i-1];
					} else {
						valor[c][i] = valor[c-N[i]][i-1] + D[i];
						peso[c][i] = peso[c-N[i]][i-1] + N[i];
					}
				}
			}
		}
		printf("Teste %d\n", c);
		printf("%d\n", valor[C][F]);
		printf("\n");
	}
	return 0;
}