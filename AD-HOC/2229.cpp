#include <stdlib.h>
#include <stdio.h>

int N;
int hline, vline;
int pow2[16];
int test, res;

int main() {
	pow2[0] = 1;
	for (int i = 1; i < 16; i++) {
		pow2[i] = pow2[i-1] * 2;
	}
	test = 1;
	while (1) {
		scanf("%d ", &N);
		if (N == -1) {
			break;
		}
		hline = pow2[N];
		vline = pow2[N];
		res = (hline+1) * (vline+1);
		printf("Teste %d\n", test);
		printf("%d\n", res);
		printf("\n");
		test++;
	}
	return 0;
}