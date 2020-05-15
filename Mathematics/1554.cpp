#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define INF 22222222

int N;
int T;
int D, M, I;
int X, Y, A, B;
int distance(int x1, int y1, int x2, int y2) {
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
} 

int main() {

	scanf("%d ", &T);
	while (T) {
		scanf("%d ", &N);
		scanf("%d %d ", &X, &Y);
		M = INF;
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &A, &B);
			D = distance(X, Y, A, B);
			if (D < M) {
				M = D;
				I = i+1;
			}
		}

		printf("%d\n", I);
		T--;
	}
	return 0;
}