#include <stdlib.h>
#include <stdio.h>

unsigned N;
int K;
unsigned max, min;

void swap(int a, int b) {
	int maskA = 1 << a;
	int maskB = 1 << b;
	int va = N & maskA;
	int vb = N & maskB;
	if (va && !vb || !va && vb) {
		if (va) {
			N -= maskA;
			N += maskB;
		} else {
			N -= maskB;
			N += maskA;
		}
	}
}

int main() {
	while (1) {
		scanf("%u %d ", &N, &K);
		if (!N && !K) {
			break;
		}
		max = N;
		min = N;
		int a, b;
		for (int i = 0; i < K; i++) {
			scanf("%d %d ", &a, &b);
			swap(a, b);
			if (N > max) {
				max = N;
			}
			if (N < min) {
				min = N;
			}
		}
		printf("%u %u %u\n", N, max, min);
	}
	return 0;
}