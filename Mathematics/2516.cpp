#include <stdlib.h>
#include <stdio.h>

int S, Va, Vb;

int main() {

	while (scanf("%d %d %d ", &S, &Va, &Vb) != EOF) {
		if (Va > Vb) {
			printf("%0.2Lf\n", (long double) S / (Va -Vb));
		} else {
			printf("impossivel\n");
		}
	}

	return 0;
}