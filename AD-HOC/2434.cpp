#include <stdlib.h>
#include <stdio.h>

int n, s;
int ans, v;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int main() {
	scanf("%d %d ", &n, &s);
	ans = s;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v);
		s += v;
		ans = min(ans, s);
	}

	printf("%d\n", ans);
	return 0;
}