#include <stdlib.h>
#include <stdio.h>

int N, M, X, Y;
int arr[200][200];
int C;

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int distance(int a, int b) {
	return max(abs(a - X), abs(b - Y));
}

void eval(int X, int Y) {
	int d, v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			d = distance(i, j);
			v = max(10 - d, 1);
			arr[i][j] += v;
		}
	}
}

int main() {
	int c = 0;
	scanf("%d ", &C);
	while (C) {
		scanf("%d %d %d %d ", &N, &M, &X, &Y);
		c++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d ", &arr[i][j]);
			}
		}
		X--;
		Y--;
		eval(X, Y);
		printf("Parede %d:\n", c);
		for (int i = 0; i < N; i++) {
			int f = 1;
			for (int j = 0; j < M; j++) {
				if (f) {
					f = 0;
					printf("%d", arr[i][j]);
				} else {
					printf(" %d", arr[i][j]);
				}
			}
			printf("\n");
		}
		C--;
	}
	return 0;
}