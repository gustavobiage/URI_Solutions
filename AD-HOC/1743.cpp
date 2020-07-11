#include <stdlib.h>
#include <stdio.h>

int X[10];
int Y[10];

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d ", &X[i]);
	}
	for (int i = 0; i < 5; i++) {
		scanf("%d ", &Y[i]);
	}
	int r = 1;
	for (int i = 0; i < 5; i++) {
		r = r && X[i] ^ Y[i];
	}
	if (r) {
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}