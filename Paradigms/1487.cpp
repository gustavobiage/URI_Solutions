#include <stdlib.h>
#include <stdio.h>

int N, T;

int D[200], P[200];
int DP[602];
int V[602];
int main() {
	int index = 0;
	while (1) {
		
		scanf("%d %d ", &N, &T);
		
		if (N == 0) {
			break;
		}

		index += 1;

		for (int i = 1; i <= N; i++) {
			scanf("%d %d ", &D[i], &P[i]);
			// printf("D[%d] = %d, P[%d] = %d\n", i, D[i], i, P[i]);
		}

		for (int i = 0; i <= T; i++) {
			V[i] = 0;
		}

		for (int i = 0; i <= T; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[j] <= i) {	
					if (V[i-D[j]] + P[j] > V[i]) {
						V[i] = V[i-D[j]] + P[j];
					}
				}

			}
		}

		printf("Instancia %d\n", index);
		printf("%d\n", V[T]);
		printf("\n");
	}

	return 0;
}