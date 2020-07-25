#include <stdlib.h>
#include <stdio.h>

int N, C;
int s, e;
int amnt;
int ans;

int main() {
	scanf("%d %d ", &N, &C);
	ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &s, &e);
		amnt += e;
		amnt -= s;
		if (amnt > C) {
			ans = 1;
		}
	}
	if (ans) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}