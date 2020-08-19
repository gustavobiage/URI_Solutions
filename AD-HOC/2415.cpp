#include <stdlib.h>
#include <stdio.h>

int n, v;
int cnt, last;
int max_;

int main() {
	scanf("%d ", &n);
	max_ = -1;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v);
		if (v == last) {
			cnt++;
		} else {
			last = v;
			cnt = 1;
		}
		if (cnt > max_) {
			max_ = cnt;
		}
	}
	printf("%d\n", max_);
	return 0;
}