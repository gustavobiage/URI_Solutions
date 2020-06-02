#include <stdlib.h>
#include <stdio.h>

int N;
int A[3], B[3];
int pa, pb, ra, rb;

int valueOf(int n) {
	if (n == 12) {
		return 8;
	} else if (n == 11) {
		return 9;
	} else if (n == 13) {
		return 10;
	} else if (n == 1) {
		return 14;
	} else if (n == 2) {
		return 15;
	} else if (n == 3) {
		return 16;
	}
	return n;
}

int cmp(int a, int b) {
	return a - b;
}

int main() {
	scanf("%d ", &N);
	pa = 0;
	pb = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d ", &A[j]);
		}
		for (int j = 0; j < 3; j++) {
			scanf("%d ", &B[j]);
		}

		ra = rb = 0;
		for (int j = 0; j < 3; j++) {
			if (cmp(valueOf(A[j]), valueOf(B[j])) >= 0) {
				ra++;		
			} else {
				rb++;
			}
		}

		if (ra > rb) {
			pa++;
		} else {
			pb++;
		}
	}

	printf("%d %d\n", pa, pb);

	return 0;
}