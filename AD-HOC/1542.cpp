#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Q, D, P;
long double d2;
int p;

int main() {
	while (1) {
		scanf("%d ", &Q);
		if (!Q) {
			break;
		}
		scanf("%d %d ", &D, &P);
		d2 = D / ((double)P/Q - 1) + 1e-9;
		p = d2*P;
		if (p > 1) {
			printf("%d paginas\n", p);
		} else {
			printf("%d pagina\n", p);
		}
	}
	return 0;
}