#include <stdlib.h>
#include <stdio.h>

int N;
int arr[15];
int total;

int cmp(const void * a, const void * b) {
	int v1 = *((int*) a);
	int v2 = *((int*) b);
	return v2 - v1;
}

int main() {
	scanf("%d ", &N);
	total = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
		total += arr[i];
	}

	qsort(arr, N, sizeof(int), cmp);

	if ((long double)arr[0] / total >= 0.45 - 1e-9 || (long double)arr[0] / total >= 0.40 - 1e-9 && arr[0] - arr[1] >= ((long double) total * 0.1) - 1e-9) {
		printf("1\n");
	} else {
		printf("2\n");
	}

	return 0;
}