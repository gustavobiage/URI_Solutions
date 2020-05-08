#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N;
double rel2 = (double)7 / 90;
double rel1 = (double)1 / 90;
int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		printf("Brasil %d x Alemanha %d\n", (int)floor(rel1*N), (int)ceil(rel2*N));
	}
	return 0;
}