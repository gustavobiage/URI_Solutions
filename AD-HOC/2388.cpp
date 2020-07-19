#include <stdlib.h>
#include <stdio.h>

int N;
int T, V;
int dist;

int main() {
	scanf("%d ", &N);
	dist = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &T, &V);
		dist += T * V;
	}
	printf("%d\n", dist);
	return 0;
}