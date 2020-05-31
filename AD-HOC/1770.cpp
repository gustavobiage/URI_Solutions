#include <stdlib.h>
#include <stdio.h>

int M, K;
int v, c, t;
int arr[102];
int listen[102];

int main() {

	while (scanf("%d %d ", &M, &K) != EOF) {

		for (int i = 0; i < M; i++) {
			scanf("%d ", &arr[i+1]);
			listen[i+1] = 0;
		}

		c = 0;
		t = 0;
		for (int i = 0; i < K; i++) {
			scanf("%d ", &v);
			if (c != M) {
				t += arr[v];
				c += !listen[v];
			}
			listen[v] = 1;
		}
		if (c == M) {
			printf("%d\n", t);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}