#include <stdlib.h>
#include <stdio.h>

int T;
int D, I, B, Q;
int price[102];
int n, q;
int total, max;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d %d ", &D, &I, &B);
		max = 0;
		for (int i = 0; i < I; i++) {
			scanf("%d ", &price[i]);
		}
		for (int i = 0; i < B; i++) {
			scanf("%d ", &Q);
			total = 0;
			for (int j = 0; j < Q; j++) {
				scanf("%d %d ", &n, &q);
				total += q*price[n];
			}
			if (D / total > max) {
				max = D / total;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}