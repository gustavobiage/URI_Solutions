#include <stdlib.h>
#include <stdio.h>

int B, U;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {

	while (scanf("%d %d ", &B, &U) != EOF) {
		printf("%d\n", max(0, abs(U - B) - 1));
	}

	return 0;
}