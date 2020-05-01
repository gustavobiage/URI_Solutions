#include <stdlib.h>
#include <stdio.h>

double V;
int M, N;
int mult;
int points[] = {0, 0, 50, 500, 3000};

int group(int n) {
	if (n == 0) {
		return 24;
	}

	int v = n % 100;
	return (v-1) / 4;
}

int eval(int A, int B) {
	int a = A;
	int b = B;

	if (a == b) {
		return 3000;
	}

	int c = 0;
	int v1, v2;
	while ((a || b) && c < 4) {
		v1 = a % 10;
		v2 = b % 10;
		a = a / 10;
		b = b / 10;
		if (v1 == v2) {
			c++;
		} else {
			break;
		}
	}

	if (points[c] != 0) {
		return points[c];
	}
	
	if (group(A) == group(B)) {
		return 16;
	}

	return 0;
}

int main() {

	while (1) {
		scanf("%lf %d %d ", &V, &N, &M);
		if (V == 0.0 && N == 0 && M == 0) {
			break;
		}

		mult = eval(N, M);
		printf("%0.2lf\n", V * mult);
	}
	return 0;
}