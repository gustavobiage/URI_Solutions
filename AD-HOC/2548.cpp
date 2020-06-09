#include <stdlib.h>
#include <stdio.h>

int arr[1001];
int N, M;
long long int ans;

int cmp(const void * a, const void * b) {
	int v1 = *((int *)a);
	int v2 = *((int *)b);
	return v2 - v1;
}

int main() {
	while (scanf("%d %d ", &N, &M) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		qsort(arr, N, sizeof(int), cmp);
		ans = 0;
		for (int i = 0; i < M; i++) {
			ans += arr[i];
		}
		printf("%Ld\n", ans);
	}
}