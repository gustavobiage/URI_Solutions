#include <stdlib.h>
#include <stdio.h>

int A[20], B[20];
int R;
int f;
int lastA, countA, lastB, countB;
int pa, pb;

int main() {

	while (1) {
		scanf("%d ", &R);
		if (!R) {
			break;
		}
		pa = pb = 0;

		for (int i = 0; i < R; i++) {
			scanf("%d ", &A[i]);
		}

		for (int i = 0; i < R; i++) {
			scanf("%d ", &B[i]);
		}
		lastB = lastA = -1;
		countB = countA = 0;

		f = 1;
		for (int i = 0; i < R; i++) {
			pa += A[i];
			pb += B[i];

			if (lastA == A[i]) {
				countA++;
			} else {
				lastA = A[i];
				countA = 1;
			}
			
			if (lastB == B[i]) {
				countB++;
			} else {
				lastB = B[i];
				countB = 1;
			}
			
			if (f && (countA == 3 || countB == 3) ) {
				f = 0;
				if (countA == 3 && countB != 3) {
					pa += 30;
				} else if (countA != 3 && countB == 3) {
					pb += 30;
				}
			}
		}

		if (pa == pb) {
			printf("T\n");
		} else if (pa > pb) {
			printf("M\n");
		} else if (pb > pa) {
			printf("L\n");
		}
	}
	return 0;
}