#include <stdlib.h>
#include <stdio.h>

int x[101], y[101], w[101];
int n, k, v;
int cnt, res;
int lastx, lasty;

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int distance(int x1, int y1, int x2, int y2) {
	return abs(x1-x2) + abs(y1-y2);
}

int main() {
	scanf("%d %d ", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d ", &x[i], &y[i], &w[i]);
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = 1;
			for (int l = 0; l < k; l++) {
				v = distance(i, j, x[l], y[l]);
				if (v != w[l]) {
					res = 0;
					break;
				}
			}
			if (res) {
				lastx = i;
				lasty = j;
				cnt++;
			}
		}
	}
	if (cnt == 1) {
		printf("%d %d\n", lastx, lasty);
	} else {
		printf("-1 -1\n");
	}
	return 0;
}