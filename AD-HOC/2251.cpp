#include <stdlib.h>
#include <stdio.h>

int power(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res = res * a;
	}
	return res;
}

int nanoi(int n) {
	return power(2, n) - 1;
}

int main() {

	int N;
	int count = 0;
	while (1) {
		count++;
		scanf("%d ", &N);
		if (N == 0) {
			break;
		}
		printf("Teste %d\n", count);
		printf("%d\n", nanoi(N));
		printf("\n");
	}

	return 0;
}