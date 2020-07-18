#include <stdlib.h>
#include <stdio.h>

int C, P, F;

int main() {
	scanf("%d %d %d ", &C, &P, &F);
	if (P/C >= F) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}