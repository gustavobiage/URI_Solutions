#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int A, B, C;
int vol;

int main() {
	while (1) {
		scanf("%d %d %d ", &A, &B, &C);
		if (!A && !B && !C) {
			break;
		}
		vol = A*B*C;
		printf("%d\n", (int) (cbrt(vol) + 1e-9));
	}
	return 0;
}