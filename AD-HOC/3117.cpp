#include <stdlib.h>
#include <stdio.h>

int cnt;
int n, k;
int v;

int main() {
	scanf("%d %d ", &n, &k);
	cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v);
		if (v <= 0) {
			cnt++;
		}
	}
	if (cnt >= k) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}