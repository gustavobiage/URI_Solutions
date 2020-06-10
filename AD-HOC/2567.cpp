#include <stdlib.h>
#include <stdio.h>

int N;
int arr[1000];
int begin, end;
int ans;

int cmp(const void * a, const void * b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v1 - v2;
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		qsort(arr, N, sizeof(int), cmp);
		ans = 0;
		begin = 0;
		end = N-1;
		while (begin < end) {
			ans += arr[end] - arr[begin];
			end--;
			begin++;
		}
		printf("%d\n", ans);
	}
	return 0;
}