#include <stdlib.h>
#include <stdio.h>

int A, B;
int d1, d2;
int res;
int N;

int main() {
	scanf("%d ", &N);
	while (N) {
		scanf("%d %d ", &A, &B);
		res = A >= B;
		if (A >= B) {
			while (A != 0 && B != 0) {
				d1 = A % 10;
				d2 = B % 10;
				A = A / 10;
				B = B / 10;
				if (d1 != d2) {
					res = 0;
					break;
				}
			}
		}

		if (res) {
			printf("encaixa\n");
		} else {
			printf("nao encaixa\n");
		}
		N--;
	}
}