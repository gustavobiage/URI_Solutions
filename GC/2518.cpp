#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N, L, H, C;

int main() {
	while (scanf("%d %d %d %d ",&N, &H, &C, &L) != EOF) {
		double hip = sqrt(C*C + H*H);
		double area = hip * N * L;
		printf("%0.4lf\n", area / 10000);
	}
	return 0;
}
