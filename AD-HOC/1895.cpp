#include <stdlib.h>
#include <stdio.h>

int N, T0, L;
int v, c;
int points[2];
int turn;

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int main() {
	turn = 0;
	scanf("%d %d %d ", &N, &T0, &L);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d ", &v);
		c = abs(T0 - v);
		if (c <= L) {
			points[turn] += c;
			T0 = v;
		}
		turn = (turn + 1) % 2;
	}

	printf("%d %d\n", points[0], points[1]);
	return 0;
}