#include <stdlib.h>
#include <stdio.h>

int L, C, X, Y;

int main() {
	scanf("%d %d %d %d ", &L, &C, &X, &Y);
	int c = X*C + Y+1;
	if (c & 1) {
		printf("Direita\n");
	} else {
		printf("Esquerda\n");
	}
	return 0;
}