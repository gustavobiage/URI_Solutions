#include <stdlib.h>
#include <stdio.h>

int last;
int next;
int A, P, N;
int c, m;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {

	scanf("%d %d ", &A, &P);
	m = 0;

	for (int i = 0; i < A; i++) {
		scanf("%d ", &N);
		last = -1;
		c = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d ", &next);
			if (next < last) {
				c++;
			}
			last = next;
		}
		if (next != 0) {
			c++;
		}
		m = max(m, c);
	}

	printf("%d\n", m);
	return 0;
}