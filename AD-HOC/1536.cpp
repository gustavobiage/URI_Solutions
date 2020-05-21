#include <stdlib.h>
#include <stdio.h>

struct t {
	int g;
	int p;
	int f;
};

int cmp(struct t * a, struct t * b) {
	if (a->p != b->p) {
		return a->p - b->p;
	}
	
	if (a->g != b->g) {
		return a->g - b->g;
	}

	return a->f - b->f;
}

int N;
struct t A, B;
int a, b;
int main() {

	scanf("%d ", &N);
	while (N) {
		A.g = 0;
		A.p = 0;
		A.f = 0;
		B.g = 0;
		B.p = 0;
		B.f = 0;

		scanf("%d x %d ", &a, &b);
		A.g += a;
		B.f += b;
		B.g += b;

		if (a > b) {
			A.p += 3;
		} else if (b > a) {
			B.p += 3;
		} else {
			A.p += 1;
			B.p += 1;
		}

		scanf("%d x %d ", &a, &b);
		A.g += b;
		A.f += b;
		B.g += a;

		if (a > b) {
			B.p += 3;
		} else if (b > a) {
			A.p += 3;
		} else {
			A.p += 1;
			B.p += 1;
		}

		int c = cmp(&A, &B);
		// printf("%d %d %d %d %d\n", A.p, A.g, B.p, B.g, c);
		if (c > 0) {
			printf("Time 1\n");
		} else if (c < 0) {
			printf("Time 2\n");
		} else {
			printf("Penaltis\n");
		}
		N--;
	}
	return 0;
}