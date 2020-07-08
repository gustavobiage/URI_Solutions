#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int T;
int N, C, M;
int arr[50001];
long long int cnt;
int pointer;

int cmp(const void * a, const void * b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v2 - v1;
}

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d %d ", &N, &C, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d ", &arr[i]);
		}
		qsort(arr, M, sizeof(int), cmp);
		pointer = 0;
		cnt = 0;
		while (pointer < M) {
			cnt += arr[pointer]*2;
			pointer += C;
			pointer = fmin(pointer, M);
		}
		printf("%Ld\n", cnt);
	}
	return 0;
}