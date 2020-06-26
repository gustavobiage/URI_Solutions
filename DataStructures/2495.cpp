#include <stdlib.h>
#include <stdio.h>

int N;
long long int total;
int v;

int main() {
	while (scanf(" %d ", &N) != EOF) {
		total = 0;
		for (int i = 1; i <= N; i++) {
			total = total + i;
		}
		// total = N*(N+1)/2; this formula gets 5% WA, not sure why!
		for (int i = 0; i < N-1; i++) {
			scanf("%d ", &v);
			total -= v;
		}
		printf("%Ld\n", total);
	}
	return 0;
}