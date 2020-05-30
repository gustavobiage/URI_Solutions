#include <stdlib.h>
#include <stdio.h>

int N, M;
int D, E, F;
char op, A, B;
int X;

void red(char c, int x) {
	if (c == 'D') {
		D -= x;
	} else if (c == 'E') {
		E -= x;
	} else if (c == 'F') {
		F -= x;
	}
}

void add(char c, int x) {
	if (c == 'D') {
		D += x;
	} else if (c == 'E') {
		E += x;
	} else if (c == 'F') {
		F += x;
	}
}

int main() {

	scanf("%d %d ", &N, &M);
	D = E= F = N;
	for (int i = 0; i < M; i++) {
		scanf("%c ", &op);
		if (op == 'C') {
			scanf("%c %d ", &A, &X);
			red(A, X);
		} else if (op == 'V') {
			scanf("%c %d ", &A, &X);
			add(A, X);
		} else if (op == 'A') {
			scanf("%c %c %d ", &A, &B, &X);
			add(A, X);
			red(B, X);
		}
	}

	printf("%d %d %d\n", D, E, F);
	return 0;
}