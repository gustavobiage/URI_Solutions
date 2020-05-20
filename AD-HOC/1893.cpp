#include <stdlib.h>
#include <stdio.h>

int A, B, delta;

void eval(int n, int delta) {
	if (n >= 0 && n <= 2) {
		printf("nova\n");
	} else if (n >= 3 && n <= 96) {
		if (delta >= 0) {
			printf("crescente\n");
		} else {
			printf("minguante\n");
		}
	} else if (n >= 97 && n <= 100) {
		printf("cheia\n");
	}
}

int main() {
	scanf("%d %d ", &A, &B);
	delta = B - A;
	eval(B, delta);
	return 0;
}