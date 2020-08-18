#include <stdlib.h>
#include <stdio.h>

int n;
int t, t_, total;
int main() {
	while (1) {
		scanf("%d ", &n);
		if (!n) {
			break;
		}
		t_ = total = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d ", &t);
			if (t < t_) {
				total += (t+10) - t_;
				t_ = t + 10;
			} else {
				t_ = t+10;
				total += 10;
			}
		}
		printf("%d\n", total);
	}
	return 0;
}