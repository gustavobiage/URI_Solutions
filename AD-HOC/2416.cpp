#include <stdlib.h>
#include <stdio.h>

int C, N;

int main() {
	scanf("%d %d ", &C, &N);
	printf("%d\n", C % N);
	return 0;
}