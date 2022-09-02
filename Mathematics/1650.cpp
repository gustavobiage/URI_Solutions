#include <stdio.h>
#include <stdlib.h>

int M, N, C;

int main() {
	int l[2], half, amnt;
	while (1) {
		scanf("%d %d %d ", &M, &N, &C);
		if (!M && !N && !C) {
			break;
		}
		M = M - 7;
		N = N - 7;
		half = M / 2;
		l[1] = (N+1) / 2;
		l[0] = N / 2;
		amnt = half * l[1] + half * l[0] + (M & 1) * l[C];	
		printf("%d\n", amnt);
	}
	return 0;
}