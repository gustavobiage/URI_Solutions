#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N;
int la, lb;
int sa, sb;
int ans;

int search(int n, int a, int b) {
	if (!n) {
		return 1;
	}
	for (int i = a; n >= i && i <= b; i++) {
		if (search(n-i, a, b)) {
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d %d %d %d ", &N, &la, &lb, &sa, &sb);
	ans = 0;
	int rl, rs;
	ans = search(N, fmax(la, sa), fmin(lb, sb));
	if (ans) {
		printf("possivel\n");
	} else {
		printf("impossivel\n");
	}
	return 0;
}