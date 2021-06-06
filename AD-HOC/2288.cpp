#include <stdlib.h>
#include <stdio.h>

int N, M;
int X, Y;
int x_ref, y_ref;
int c;
int mat[1009][1009];

int ajust(int v, int m) {
	if (v < 0) {
		return -(-v % m);
	} else {
		return v % m;
	}
}

int mod(int v, int m) {
	return (v + m) % m;
}

int get_value(int y, int x) {
	int y_ = mod(mod(y_ref, M) + mod(y, M), M);
	int x_ = mod(mod(x_ref, N) + mod(x, N), N);
	return mat[y_][x_];
}

int main() {
	c = 0;
	while (1) {
		scanf("%d %d ", &M, &N);
		if (!N && !M) {
			break;
		}
		x_ref = y_ref = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &mat[i][j]);
			}
		}
		while (1) {
			scanf("%d %d ", &X, &Y);
			if (!X && !Y) {
				break;
			}
			x_ref -= X;
			y_ref += Y;
			x_ref = ajust(x_ref, N);
			y_ref = ajust(y_ref, M);
		}
		c++;
		printf("Teste %d\n",c);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (j == 0) {
					printf("%d", get_value(i, j));
				} else {
					printf(" %d", get_value(i, j));
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}