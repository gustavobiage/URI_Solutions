#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N;
int arr[1001];
int s[2];

int cmp(const void * a, const void * b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v1 - v2;
}

int distance(int a, int b) {
	return fmin(abs(a-b), 24 - abs(a-b));
}

int main() {

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}
	qsort(arr, N, sizeof(int), cmp);
	arr[N] = arr[0];
	for (int i = 0; i < N; i++) {
		s[i%2] += distance(arr[i], arr[i+1]);
	}
	printf("%d\n", (int)fmin(s[0], s[1]));
	return 0;
}