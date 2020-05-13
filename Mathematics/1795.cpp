#include <stdlib.h>
#include <stdio.h>

int N;

int main() {

	scanf("%d ", &N);
	long long int sum = 1;
	for (int i = 0; i < N; i++) {
		sum = sum * 3;
	}

	printf("%Ld\n", sum);
	return 0;
}