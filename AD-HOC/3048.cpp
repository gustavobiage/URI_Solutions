#include <stdlib.h>
#include <stdio.h>

int n;
int last, v;
int cnt;

int main() {
	scanf("%d ", &n);
	cnt = 0;
	last = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v);
		if (v != last) {
			cnt++;
			last = v;
		}
	}
	printf("%d\n", cnt);
	return 0;
}