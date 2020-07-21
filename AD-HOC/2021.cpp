#include <stdlib.h>
#include <stdio.h>

int N, M, P;
int q, total;
int main() {
	while (1) {
		scanf("%d %d %d ", &N, &M, &P);
		if (!N && !M & !P) {
			break;
		}
		total = 0;
		for (int i = 0; i < P; i++) {
			scanf("%d ", &q);
			q--;
			q = q % M;
			q++;
			total += M-q+1;
		}
		printf("Lights: %d\n", total);
	}
	return 0;
}