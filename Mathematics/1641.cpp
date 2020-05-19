#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int R, W, L;
double d;
double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main() {
	int c = 0;
	while (1) {
		scanf("%d ", &R);
		if (!R) {
			break;
		}
		scanf("%d %d ", &W, &L);
		c++;
		d = distance((double)W/2, (double)L/2, 0, 0);
		// printf("%lf %d\n", d, R);
		if (d <= R+1e-9) {
			printf("Pizza %d fits on the table.\n", c);
		} else {
			printf("Pizza %d does not fit on the table.\n", c);
		}
	}
	return 0;
}