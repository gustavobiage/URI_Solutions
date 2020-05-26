#include <stdlib.h>
#include <stdio.h>

int N, D, V;
long double m;
long double t;
int first;

int main() {
	first = -1;
	m = 22222222;
	while (scanf("%d %d %d ", &N, &D, &V) != EOF) {
		t = (long double) D / V;
		if (m > t) {
			m = t;
			first = N;
		}
	}

	printf("%d\n", first);
	return 0;
}