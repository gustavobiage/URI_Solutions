#include <stdlib.h>
#include <stdio.h>

#define LEFT 0
#define RIGHT 1

int l, c, p;
int arr[10][10];
int x, y;
int mcnt;
int newCol;
int a, b;
int direction;

int boom() {
	return arr[x][y];
}

int left() {
	for (int i = y; i >= 0; i--) {
		if (arr[x][i]) {
			return arr[x][i];
		}
	}
	return 0;
}

int right() {

	for (int i = y; i <= c; i++) {
		if (arr[x][i]) {
			return arr[x][i];
		}
	}
	return 0;
}

int main() {
	while (1) {
		scanf("%d %d %d ", &l, &c, &p);
		if (!l && !c && !p) {
			break;
		}
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= c; j++) {
				scanf("%d ", &arr[i][j]);
			}
		}
		x = 1;
		y = p;
		newCol = 1;
		while (x <= l) {
			if (boom()) {
				break;
			}

			if (newCol) {
				newCol = 0;
				a = left();
				b = right();
				if (a > b) {
					mcnt = a - b;
					direction = RIGHT;
				} else if (b > a) {
					mcnt = b - a;
					direction = LEFT;
				} else {
					newCol = 1;
					x++;
					continue;
				}
			}

			if (!mcnt) {
				newCol = 1;
				x++;
				continue;
			}
			mcnt--;
			if (direction == LEFT) {
				y--;
			} else {
				y++;
			}
		}
		if (x > l) {
			printf("OUT %d\n", y);
		} else {
			printf("BOOM %d %d\n", x, y);
		}
	}

	return 0;
}