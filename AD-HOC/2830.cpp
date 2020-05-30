#include <stdlib.h>
#include <stdio.h>

int K, L;

const char * name[] = {" ", "final", "semifinal", "quartas", "oitavas"};

int eval(int A, int B, int size) {
	if (A > B) {
		return eval(B, A, size);
	}

	if (A <= size/2 && B > size/2) {
		return 1;
	}

	if (A > size/2) {
		int v = eval(A - size/2, B - size/2, size/2);
		return v + 1;
	} else {
		int v = eval(A, B, size/2);
		return v + 1;
	}
}

int main() {
	scanf("%d %d ", &K, &L);
	printf("%s\n", name[eval(K, L , 16)]);
}