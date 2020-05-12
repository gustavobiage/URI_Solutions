#include <stdlib.h>
#include <stdio.h>

int N, X; 

unsigned long long int power2(int a) {
	unsigned long long int r = 1;
	unsigned long long int A = 1;
	unsigned long long int B = 0;

	for (int i = 0; i < a; i++) {
		// printf("r = %Lu\n", r);
		r = r * 2;
		A += r / 12;
		B += r % 12;
	}

	A += B / 12;
	return A / 1000;
}

int main() {
	scanf("%d ", &N);
	while (N) {
		scanf("%d ", &X);
		printf("%Lu kg\n", power2(X-1));
		N--;
	}
}