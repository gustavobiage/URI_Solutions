#include <stdlib.h>
#include <stdio.h>

struct p {
	int W, H, L;
	int I;
};

int T;
int N, K;
struct p arr[100001];
int f;

int cmp(const void * a, const void * b) {
	struct p p1 = *((struct p*)a);
	struct p p2 = *((struct p*)b);
	int v1, v2;
	v1 = p1.H * p1.W * p1.L;
	v2 = p2.H * p2.W * p2.L;
	if (v1 != v2) {
		return v2 - v1;
	} else {
		return p1.I - p2.I;
	}
}

int cmpId(const void * a, const void * b) {
	struct p p1 = *((struct p*)a);
	struct p p2 = *((struct p*)b);
	return p1.I - p2.I;
}

int main() {
	scanf("%d ", &T);
	while (T) {
		scanf("%d %d ", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d ", &arr[i].I, &arr[i].H, &arr[i].W, &arr[i].L);
		}

		qsort(arr, N, sizeof(struct p), cmp);
		qsort(arr, K, sizeof(struct p), cmpId);
		int pointer = 0;
		f = 1;
		while (pointer < K) {
			if (f) {
				f = 0;
				printf("%d", arr[pointer].I);
			} else {
				printf(" %d", arr[pointer].I);
			}
			pointer++;
		}
		printf("\n");
		T--;
	}
	return 0;
}