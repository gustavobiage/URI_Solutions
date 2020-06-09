#include <stdlib.h>
#include <stdio.h>

int A, B;
int v;
const char * name[] = {"final", "semifinal", "quartas", "oitavas"};

int find(int a, int b, int size) {
	if (a > b) {
		return find(b, a, size);
	}

	if (a <= size/2 && b > size/2) {
		return 0;
	}

	if (a > size/2) {
		a -= size/2;
		b -= size/2;
	}
	return find(a, b, size/2) + 1;
}

int  main() {
	for (int i = 1; i <= 16; i++) {
		scanf("%d ", &v);
		if (v == 1) {
			A = i;
		} else if (v == 9) {
			B = i;
		}
	}	

	printf("%s\n", name[find(A, B, 16)]);
	return 0;
}