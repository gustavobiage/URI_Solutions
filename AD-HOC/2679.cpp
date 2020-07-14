#include <stdlib.h>
#include <stdio.h>

int X;

int main() {
	scanf("%d ", &X);
	if (X%2) {
		X++;
	} else {
		X += 2;
	}
	printf("%d\n", X);
	return 0;
}