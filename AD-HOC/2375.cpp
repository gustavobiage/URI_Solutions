#include <stdlib.h>
#include <stdio.h>

int D;
int X, Y, Z;

int main() {
	scanf("%d ", &D);
	scanf("%d %d %d ", &X, &Y, &Z);
	if (X >= D && Y >= D && Z >= D) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}