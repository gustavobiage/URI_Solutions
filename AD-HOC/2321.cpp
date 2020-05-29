#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int ax0, ay0, ax1, ay1;
int bx0, by0, bx1, by1;

int main() {
	scanf("%d %d %d %d ", &ax0, &ay0, &ax1, &ay1);
	scanf("%d %d %d %d ", &bx0, &by0, &bx1, &by1);
	int x0 = fmax(ax0, bx0);
	int y0 = fmax(ay0, by0);
	int x1 = fmin(ax1, bx1);
	int y1 = fmin(ay1, by1);

	int width = x1 - x0;
	int length = y1 - y0;
	if (width >= 0 && length >= 0) {
		printf("1\n");
	} else {
		printf("0\n");
	}

	return 0;
}