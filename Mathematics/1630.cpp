#include <stdlib.h>
#include <stdio.h>

int X, Y;
int P;

int euclides(int a, int b) {
	if (a < b) {
		return euclides(b, a);
	}

	if (!b) {
		return a;
	}
	return euclides(b, a % b);
}

int main() {
	while (scanf("%d %d ", &X, &Y) != EOF) {
		int v = euclides(X, Y);
		printf("%d\n",  X/v*2 + Y/v*2);
	}
	return 0;
}