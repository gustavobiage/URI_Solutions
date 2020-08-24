#include <stdlib.h>
#include <stdio.h>

#define HOLE 0
#define POSITION 1

int n, v;
int x, y;
int ans;

void move(int n) {
	switch (n) {
		case 1: case 8:
		x -= 2;
		break;
		case 5: case 4:
		x += 2;
		break;
		case 7: case 2:
		x -= 1;
		break;
		case 6: case 3:
		x += 1;
		break;
	}

	switch (n) {
		case 7: case 6:
		y -= 2;
		break;
		case 2: case 3:
		y += 2;
		break;
		case 8: case 5:
		y -= 1;
		break;
		case 1: case 4:
		y += 1;
		break;
	}
}

int type() {
	return !((x == 5 && y == 2) || (x == 5 && y == 3) || (x == 4 && y == 6) || (x == 3 && y == 3));
}

int main() {
	x = 5; y = 5;
	scanf("%d ", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v);
		move(v);
		ans++;
		if (!type()) {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}