#include <stdlib.h>
#include <stdio.h>

int A, D;
int At[100];
int Df[100]; 

int cmp(const void * a, const void * b) {
	int v1 = *((int*) a);
	int v2 = *((int*) b);
	return v1 - v2;
}

int main() {

	while (1) {
		scanf("%d %d ", &A, &D);
		if (!A && !D) {
			break;
		}

		for (int i = 0; i < A; i++) {
			scanf("%d ", &At[i]);
		}

		for (int i = 0; i < D; i++) {
			scanf("%d ", &Df[i]);
		}

		qsort(At, A, sizeof(int), cmp);
		qsort(Df, D, sizeof(int), cmp);
		
		if (At[0] < Df[1]) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}