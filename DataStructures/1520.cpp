#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, K;
int a, b;
int cnt[101];
int pointer;

int find(int n) {
	if (n == 0) {
		return 0;
	}

	return find(n-1) + cnt[n];
}

int main() {

	while (scanf("%d ", &N) != EOF) {
		memset(cnt, 0, sizeof(int)*101);
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &a, &b);
			for (int i = a; i <= b; i++) {
				cnt[i]++;
			}
		}
		scanf("%d ", &K);
		if (!cnt[K]) {
			printf("%d not found\n", K);
		} else {
			pointer = find(K-1);
			printf("%d found from %d to %d\n", K, pointer, pointer + cnt[K] - 1);
		}
	}
	return 0;
}