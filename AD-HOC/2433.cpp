#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define INF 222222222

int N, K;
int arr[100005];

int cmp(const void * a, const void * b) {
	int v1 = *((int *) a);
	int v2 = *((int *) b);
	return v1 - v2;
}

int main() {

	scanf("%d %d ", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}

	qsort(arr, N, sizeof(int), cmp);

	int d;
	int D = N - K;
	int m = INF;
	for (int i = 0; i < N-D+1; i++) {
		d = arr[i+D-1] - arr[i];
		if (d < m) {
			m = d;
		}
	}

	printf("%d\n", m);

	return 0;
}