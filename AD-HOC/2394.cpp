#include <stdlib.h>
#include <stdio.h>

struct o {
	int v;
	int id;
};

int n, m;
struct o arr[101];
int v;

int cmp(const void * a, const void * b) {
	struct o o1 = *((struct o *)a);
	struct o o2 = *((struct o *)b);
	return o1.v - o2.v;
}

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		arr[i].id = i+1;
		arr[i].v = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d ", &v);
			arr[i].v += v;
		}
	}
	qsort(arr, n, sizeof(struct o), cmp);
	printf("%d\n", arr[0].id);
	return 0;
}