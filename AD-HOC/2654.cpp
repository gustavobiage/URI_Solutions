#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
struct g {
	char name[1000];
	int p;
	int k;
	int m;
};

struct g arr[102];

int cmp(const void * a, const void * b) {
	struct g v1 = *((struct g *) a);
	struct g v2 = *((struct g *) b);

	if (v1.p != v2.p) {
		return v2.p - v1.p;
	} else if (v1.k != v2.k) {
		return v2.k - v1.k;
	} else if (v1.m != v2. m) {
		return v1.m - v2.m;
	}

	return strcmp(v1.name, v2.name);
}

int main() {

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d ", arr[i].name, &arr[i].p, &arr[i].k, &arr[i].m);
	}

	qsort(arr, N, sizeof(struct g), cmp);

	printf("%s\n", arr[0].name);
	return 0;
}