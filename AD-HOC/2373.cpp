#include <stdlib.h>
#include <stdio.h>

int N;
int L, C;
int cnt;

int main() {
	scanf("%d ", &N);
	cnt = 0;
	while (N--) {
		scanf("%d %d ", &L, &C);
		if (L > C) {
			cnt += C;
		}
	}
	printf("%d\n", cnt);
	return 0;
}