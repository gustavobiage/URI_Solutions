#include <stdlib.h>
#include <stdio.h>

int N, M;
int g, v, c;

int main() {
	c = 0;
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		g = 1;
		for (int j = 0; j < M; j++) {
			scanf("%d ", &v);
			g = g && v;
		}
		if (g) {
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}