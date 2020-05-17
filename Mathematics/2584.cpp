#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int T, N;
double H, area;
int main() {
	scanf("%d ", &T);
	double rad = 54*M_PI/180.0;

	while (T) {
		scanf("%d ", &N);
		H = tan(rad)*N;
		area = 5 * (N*H) / 4;
		printf("%0.3lf\n", area);
		T--;
	}
	return 0;
}