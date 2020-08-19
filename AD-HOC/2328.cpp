#include <stdlib.h>
#include <stdio.h>

int n, v;
int cnt;

int main() {
	cnt = 0;
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v);
		cnt += v - 1;
	}
	printf("%d\n", cnt);
	return 0;
}