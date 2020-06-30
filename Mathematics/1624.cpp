#include <stdlib.h>
#include <stdio.h>

int N, M;
int peso[101];
int preco[102];
int pesoDP[200][200];
int precoDP[200][200];

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d %d ", &preco[i], &peso[i]);
		}
		scanf("%d ", &M);
		for (int c = 1; c <= M; c++) {
			for (int i = 1; i <= N; i++) {
				if (peso[i] > c) {
					pesoDP[c][i] = pesoDP[c][i-1];
					precoDP[c][i] = precoDP[c][i-1];
				} else if (pesoDP[c][i-1] + peso[i] <= c) {
					pesoDP[c][i] = pesoDP[c][i-1] + peso[i];
					precoDP[c][i] = precoDP[c][i-1] + preco[i];
				} else if (precoDP[c][i-1] >= precoDP[c-peso[i]][i-1] + preco[i]) {
					pesoDP[c][i] = pesoDP[c][i-1];
					precoDP[c][i] = precoDP[c][i-1];
				} else {
					pesoDP[c][i] = pesoDP[c-peso[i]][i-1] + peso[i];
					precoDP[c][i] = precoDP[c-peso[i]][i-1] + preco[i];
				}
			}
		}
		printf("%d\n", precoDP[M][N]);
	}

	return 0;
}