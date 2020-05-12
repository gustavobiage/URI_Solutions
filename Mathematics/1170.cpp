#include <stdlib.h>
#include <stdio.h>

int N;
double C, c;
int res;

int main() {

	scanf("%d ", &N);
	while (N) {
		scanf("%lf ", &C);
		c = C;
		res = 0;
		while (c > 1) {
			c = c / 2;
			res++;
		}

		printf("%d dias\n", res);

		N--;
	}
	return 0;
}