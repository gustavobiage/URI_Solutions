#include <stdlib.h>
#include <stdio.h>

#define MOD 1000000007

int N, K;
int arr[1000001];
int sum;

int cmp(const void * a, const void * b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v2 - v1;
}

int main() {
	while (scanf("%d %d ", &N, &K) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		qsort(arr, N, sizeof(int), cmp);
		sum = 0;
		for (int i = 0; i < K; i++) {
			sum = (sum + arr[i]) % MOD;
		}
		printf("%d\n", sum);
	}
	return 0;
}