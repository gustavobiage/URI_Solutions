#include <stdlib.h>
#include <stdio.h>

int C, N;
int c;
int main() {

	scanf("%d ", &C);
	while (C) {
		scanf("%d ", &N);
		c = 0;
		for (int i = 1; i * i <= N; i++) {
			c++;
		}
		printf("%d\n", N-c);
		C--;
	}
	return 0;
}