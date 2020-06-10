#include <stdlib.h>
#include <stdio.h>

int N, M;
int B;
int sum, ans, ans2;
int v, val;
int valueFrom(int n) {
	if (n >= 10000) {
		return 10000;
	} else if (n >= 1000) {
		return 1000;
	} else if (n >= 100) {
		return 100;
	} else if (n >= 10) {
		return 10;
	} else if (n >= 1) {
		return 1;
	}
	return 0;
}

int main() {

	scanf("%d %d ", &N, &M);
	ans = ans2 = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %d ", &B, &val);
		sum = 0;
		for (int j = 0; j < N-1; j++) {
			scanf("%d ", &v);
			sum += v;
		}
		ans += valueFrom(B-sum);
		sum += val;
		if (sum <= B) {
			ans2 += val;
		}
	}
	printf("%d\n", ans - ans2);
	return 0;
}