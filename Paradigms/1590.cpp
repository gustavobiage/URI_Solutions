#include <stdlib.h>
#include <stdio.h>
	
int T;
int N, K;
unsigned arr[10001];
int ans;

int search(int index, int k, int n) {
	if (!k || !n) {
		return n;
	}
	if (index > N) {
		return 0;
	}
	int m = 0;
	int v;
	for (int i = index; i <= N; i++) {
		v = search(i+1, k-1, n&arr[i]);
		if (v > m) {
			m = v;
		}
	}
	return m;
}

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%u ", &arr[i]);
		}
		ans = search(1, K, 4294967295); // 4294967295 contains all bits equals 1
		printf("%d\n", ans);
	}
	return 0;
}