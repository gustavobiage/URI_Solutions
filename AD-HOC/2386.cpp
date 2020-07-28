#include <stdlib.h>
#include <stdio.h>

int A, N;
int F, cnt;

int main() {
	cnt = 0;
	scanf("%d ", &A);
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &F);
		if (F*A >= 40000000) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}