#include <stdlib.h>
#include <stdio.h>

int N, n;
int delta;

void prt(int n, int N) {
	delta = N - n;
	for (int i = 0; i < delta/2; i++) {
		printf(" ");
	}
	for (int i = 0; i < n; i++) {
		printf("*");
	}
	printf("\n");
}

int main() {

	while (scanf("%d ", &N) != EOF) {
		n = 1;
		while (n <= N) {
			prt(n, N);
			n += 2;
		}
		prt(1, N);
		prt(3, N);
		printf("\n");
	}
	return 0;
}