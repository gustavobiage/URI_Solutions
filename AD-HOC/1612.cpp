#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int T;
int N;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		printf("%d\n", N/2 + N%2);
	}
	return 0;
}