#include <stdlib.h>
#include <stdio.h>

int M, N;
int sum, v;

int main() {
	while (scanf("%d %d ", &M, &N) != EOF) {
		sum = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &v);
				sum += v;
			}
		}
		printf("%d saca(s) e %d litro(s)\n", sum / 60, sum % 60);
	}
	
	return 0;
}