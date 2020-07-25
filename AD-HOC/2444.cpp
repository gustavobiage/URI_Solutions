#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int V, T;
int v;

int main() {
	scanf("%d %d ", &V, &T);
	for (int i = 0; i < T; i++) {
		scanf("%d ", &v);
		if (v > 0) {
			V = fmin(100, V+v);
		} else {
			V = fmax(0, V+v);
		}
	}
	printf("%d\n", V);
	return 0;
}