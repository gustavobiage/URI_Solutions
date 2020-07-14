#include <stdlib.h>
#include <stdio.h>

int A, B, C;

int main() {
	while (1) {
		scanf("%d %d ", &A, &B);
		if (!A && !B) {
			break;
		}
		if (A > B) {
			int aux = A;
			A = B;
			B = aux;
		}
		printf("%d\n", A - (B-A));
	}
	return 0;
}