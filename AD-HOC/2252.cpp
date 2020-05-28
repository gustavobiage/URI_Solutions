#include <stdlib.h>
#include <stdio.h>

int N, c;
struct a {
	int t;
	long long int n;
};
struct a arr[10];

int cmp(const void * a, const void * b) {
	struct a * v1 = (struct a *) a;
	struct a * v2 = (struct a *) b;
	return v2->n - v1->n;
}

int main() {
	c = 0;
	while (scanf("%d ", &N) != EOF) {
		c++;
		for (int i = 0; i < 10; i++) {
			arr[i].t = i;
			scanf("0.%Ld ", &arr[i].n);
		}
		qsort(arr, 10, sizeof(struct a), cmp);
		printf("Caso %d: ", c);
		for (int i = 0; i < N; i++) {
			printf("%d", arr[i].t);
		}
		printf("\n");
	}
	return 0;
}