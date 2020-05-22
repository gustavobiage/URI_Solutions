#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int T, N;
long long unsigned arr[200][200];
int max_col[200];
int dig_counter[200][200];
int f, first_case;

int getDigits(long long unsigned n) {
	if (!n) {
		return 1;
	}

	int c = 0;
	while (n) {
		n = n / 10;
		c++;	
	}
	return c;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

void prt(int a, int b) {
	if (!f) {
		printf(" ");
	} else {
		f = 0;
	}

	for (int i = dig_counter[a][b]; i < max_col[b]; i++) {
		printf(" ");
	}
	printf("%Lu", arr[a][b]);
}

int main() {
	first_case = 1;
	scanf("%d ", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d ", &N);

		if (first_case) {
			first_case = 0;
		} else {
			printf("\n");
		}

		for (int i = 0; i < N; i++) {
			max_col[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%Lu ", &arr[i][j]);
				arr[i][j] = arr[i][j] * arr[i][j];
				dig_counter[i][j] = getDigits(arr[i][j]);
				max_col[j] = max(max_col[j], dig_counter[i][j]);
			}
		}

		printf("Quadrado da matriz #%d:\n", 3+t);

		for (int i = 0; i < N; i++) {
			f = 1;
			for (int j = 0; j < N; j++) {
				prt(i, j);
			}
			printf("\n");
		}
	}
}