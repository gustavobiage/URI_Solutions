#include <stdlib.h>
#include <stdio.h>

int N;
struct m {
	int d;
	int t;
};

struct m arr[5003];

int cmp(const void * a, const void * b) {
	struct m v1 = *((struct m*)a);
	struct m v2 = *((struct m*)b);
	return v1.d - v2.d;
}

int main() {

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &arr[i].d, &arr[i].t);
	}

	qsort(arr, N, sizeof(struct m), cmp);

	int res = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i].t > arr[i-1].t) {
			res = 0;
			break;
		}
	}

	if (res) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}