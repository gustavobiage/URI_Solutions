#include <stdlib.h>
#include <stdio.h>

int N, K;
int cnt[101];
int v, ans;

int main() {
	while (1) {
		scanf("%d %d ", &N, &K);
		if (!N && !K) {
			break;
		}
		for (int i = 0; i <= 100; i++) {
			cnt[i] = 0;
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			cnt[v]++;
			if (cnt[v] == K) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}