#include <stdlib.h>
#include <stdio.h>

int N;
int has[10];

int main() {

	scanf("%d ", &N);

	int A1, A2, B1, B2, C1 ,C2;
	while (N) {
		scanf("%d ", &A1);
		scanf("%d %d %d %d ", &B1, &C1, &B2, &C2);
		scanf("%d ", &A2);

		for (int i = 1; i <= 6; i++) {
			has[i] = 0;
		}

		if (A1 > 0 && A1 < 10)
			has[A1]++;
		if (A2 > 0 && A2 < 10)
			has[A2]++;
		if (B1 > 0 && B1 < 10)
			has[B1]++;
		if (B2 > 0 && B2 < 10)
			has[B2]++;
		if (C1 > 0 && C1 < 10)
			has[C1]++;
		if (C2 > 0 && C2 < 10)
			has[C2]++;

		for (int i = 1; i <= 6; i++) {
			if (has[i] != 1) {
				goto NOT;
			}
		}
		
		if (A1 + A2 == 7 &&
			B1 + B2 == 7 &&
			C1 + C2 == 7) {
			printf("SIM\n");
		} else {
			NOT:
			printf("NAO\n");
		}
		
		N--;
	}
	return 0;
}