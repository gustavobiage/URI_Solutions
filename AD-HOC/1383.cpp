#include <stdio.h>
#include <stdlib.h>

int N;
int arr[9][9];
int check[10];

int reset() {
	for (int i = 1; i <= 9; i++) {
		check[i] = 0;
	}
}

int block(int i, int j) {
	reset();
	int sum = 0;
	for (int a = i; a < i+3; a++) {
		for (int b = i; b < i+3; b++) {
			if (check[arr[a][b]]) {
				// printf("%d %d\n", a, b);
				return 0;
			}
			check[arr[a][b]] = 1;
		}
	}

	return 1;
}

int main() {

	scanf("%d ", &N);
	int r, c = 0;
	int sum;
	while (N) {
		r = 1;
		c++;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d ", &arr[i][j]);
			}
		}
		
		for (int i = 0; i < 9; i++) {
			sum = 0;
			reset();
			for (int j = 0; j < 9; j++) {
				if (check[arr[i][j]]) {
					r = 0;
					goto END;
				}
				check[arr[i][j]] = 1;
			}
		}

		for (int i = 0; i < 9; i++) {
			sum = 0;
			reset();
			for (int j = 0; j < 9; j++) {
				if (check[arr[j][i]]) {
					r = 0;
					goto END;
				}
				check[arr[j][i]] = 1;
			}
		}
		
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				r = r && block(i, j);
			}
		}
		
		END:
		printf("Instancia %d\n", c);
		if (r) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
		printf("\n");
		N--;
	}
	return 0;
}