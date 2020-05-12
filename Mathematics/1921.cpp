#include <stdlib.h>
#include <stdio.h>

long long int N;

int main() {

	scanf("%Ld ", &N);
	printf("%Ld\n", (N * (N-3)) / 2);
	return 0;
}