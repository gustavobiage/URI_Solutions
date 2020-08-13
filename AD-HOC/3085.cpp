#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int n, k;
int xf, yf, x, y;
char op;

int distanceF(int x, int y) {
	return (x-xf)*(x-xf)+(y-yf)*(y-yf);
}

int main() {
	scanf("%d %d %d %d ", &n, &k, &xf, &yf);
	x = y = 0;
	int i = 1;
	if (distanceF(x, y) <= k*k) {
		for (i = 1; i <= n; i++) {
			scanf("%c ", &op);
			if (op == 'D') {
				x++;
			} else if (op == 'E') {
				x--;
			} else if (op == 'B') {
				y--;
			} else if (op == 'C') {
				y++;
			}
			if (distanceF(x, y) > k*k) {
				break;
			}
		}
	}
	if (i-1 == n && x == xf && y == yf) {
		printf("Sucesso\n");
	} else {
		i = fmin(i, n);
		printf("Trap %d\n", i);
	}
	return 0;
}