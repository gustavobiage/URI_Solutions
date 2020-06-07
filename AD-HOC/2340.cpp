#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N;

struct bac {
	int D;
	int	C;
	int id;
};

struct bac arr[50001];

int cmp(const void * a, const void * b) {
	struct bac v1 = *((struct bac *) a);
	struct bac v2 = *((struct bac *) b);
	if (v1.D > v2.D && v1.C > v2.C) {
		return 1;
	} else if (v2.D > v1.D && v2.C > v1.C) {
		return -1;
	}
	int c1 = v2.C * log(v2.D) / log(v1.D);
	return v1.C - c1;
}

int main() {

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &arr[i].D, &arr[i].C);
		arr[i].id = i;
	}

	qsort(arr, N, sizeof(struct bac), cmp);
	printf("%d\n", arr[N-1].id);
}