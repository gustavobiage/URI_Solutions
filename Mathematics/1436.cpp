#include <stdlib.h>
#include <stdio.h>


int T, N;
int arr[20];

int cmp(const void * a, const void * b) {
	int v1 = *((int *) a);
	int v2 = *((int *) b);
	return v1 - v2;
}

int main() {

	scanf("%d ", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}

		qsort(arr, N, sizeof(int), cmp);

		printf("Case %d: %d\n",	t+1, arr[N/2]);
	}

	return 0;

}