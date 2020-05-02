#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

void minimum_set(int n) {
	if (n == 13) {
		printf("*\n");
	} else {
		printf("%d %d %d\n", n+1, n+1, n+1);
	}
}

void minimum_par(int n, int c) {
	if (c == 13) {
		printf("%d %d %d\n", 1, n+1, n+1);
	} else if (c+1 == n) {
		if (c+1 == 13) {
			printf("1 1 1\n");
		} else {
			if (c+2 < n) {
				printf("%d %d %d\n", c+2, n, n);
			} else {
				printf("%d %d %d\n", n, n, c+2);
			}
		}
	} else {
		if (n < c+1) {
			printf("%d %d %d\n", n, n, c+1);
		} else {
			printf("%d %d %d\n", c+1, n, n);
		}
	}
}

void minimum_non_par(int a, int b, int c) {
	printf("1 1 2\n");
}

int main() {
	int A, B, C;
	while (1) {
		scanf("%d %d %d ", &A, &B, &C);
		if (A == 0 && B == 0 && C == 0) {
			break;
		}

		if (A == B && B == C) {
			minimum_set(A);
		} else if (A == B) {
			minimum_par(A, C);
		} else if (B == C) {
			minimum_par(B, A);
		} else if (A == C) {
			minimum_par(A, B);
		} else {
			minimum_non_par(A, B, C);
		}
	}
	return 0;
}