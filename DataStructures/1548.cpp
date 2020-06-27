#include <stdlib.h>
#include <stdio.h>

int N, M;
int arr[1001];
int sorted[1001];
int c;

int cmp(const void * a, const void * b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v2 - v1;
}

int main() {
	scanf("%d ", &N);
	while (N--) {
		c = 0;
		scanf("%d ", &M);
		for (int i = 0; i < M; i++) {
			scanf("%d ", &arr[i]);
			sorted[i] = arr[i];
		}
		qsort(sorted, M, sizeof(int), cmp);
		for (int j = 0; j < M; j++) {
			if (sorted[j] == arr[j]) {
				c++;
			}	
		}
		printf("%d\n", c);
	}
	return 0;
}