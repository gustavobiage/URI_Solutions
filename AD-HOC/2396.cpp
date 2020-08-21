#include <stdlib.h>
#include <stdio.h>

struct o {
	int value;
	int index;
};

int n, m;
struct o arr[101];
int s, v;

int cmp(const void * a, const void * b) {
	struct o o1 = *((struct o*)a);
	struct o o2 = *((struct o*)b);
	return o1.value - o2.value;
}

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d ", &v);
			s += v;
		}
		arr[i].value = s;
		arr[i].index = i+1;
	}
	qsort(arr, n, sizeof(struct o), cmp);
	printf("%d\n", arr[0].index);
	printf("%d\n", arr[1].index);
	printf("%d\n", arr[2].index);
	return 0;
}