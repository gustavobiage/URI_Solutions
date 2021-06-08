#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double a, b, c;

int main() {
	while (scanf("%lf %lf %lf ", &a, &b, &c) != EOF) {
		if (a + b <= c || a + c <= b || b + c <= a) {
			printf("%0.3lf\n", (double) -1);
		} else{
			double s = (a + b + c) / 2.0;
			double p = s * (s-a) * (s-b) * (s-c);
			double area = 4.0 / 3 * sqrt(p);
			printf("%0.3lf\n", area);
		}
	}
	return 0;
}