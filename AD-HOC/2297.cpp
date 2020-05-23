#include <stdlib.h>
#include <stdio.h>

int N;
int A, B;
int a, b;

int main() {
	int c = 0;

	while (1) {

		scanf("%d ", &N);
		if (!N) {
			break;
		}

		c++;
		
		A = B = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &a, &b);
			A += a;
			B += b;
		}
		printf("Teste %d\n", c);
		if (A > B) {
			printf("Aldo\n");
		} else if (B > A) {
			printf("Beto\n");
		}

		printf("\n");
	}
	return 0;
}