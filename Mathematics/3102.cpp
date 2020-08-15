#include <stdlib.h>
#include <stdio.h>

int n;
int x1, y1, x2, y2, x3, y3;
long double area;

long double abs_(long double a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int main() {
	scanf("%d ", &n);
	while (n--) {
		scanf("%d %d %d %d %d %d ", &x1, &y1, &x2, &y2, &x3, &y3);
		area = (long double) (x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3) / 2;
		printf("%0.3Lf\n", abs_(area));
	}
	return 0;
}