#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.141592654

long double A, B, C;
long double rad, alt;

int main() {
	while (scanf("%Lf %Lf %Lf ", &A, &B, &C) != EOF) {
		rad = A*PI/180;
		alt = tan(rad)*B + C;
		printf("%0.2Lf\n", 5*alt);
	}
	return 0;
}