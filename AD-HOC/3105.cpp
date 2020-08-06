#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LLD long long int

LLD N, M, K, G;

void search(int x, int y) {
	int h = (x+1)*(y+1);
	if (h > K) {
		return;
	}
	long double g = fmax((long double) M/(x+1), (long double) N/(y+1));
	if (ceil(g) < G) {
		G = ceil(g);
	}
	if (M*(y+1) > N*(x+1)) {
		search(x+1, y);
	} else if (M*(y+1) < N*(x+1)) {
		search(x, y+1);
	} else if ((x+1)*y < x*(y+1)) {
		search(x+1, y);
	} else {
		search(x, y+1);
	}
}

int main() {
	scanf("%Ld %Ld %Ld ", &N, &M, &K);
	G = 1000000000000000000;
	search(0, 0);
	printf("%Ld\n", G);
	return 0;
}