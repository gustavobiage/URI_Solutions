#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897

int A, B, C; // TRIANGLE SIDES
long double SP; // SEMI PERIMETER
long double TA, SA, IA; // (TRIANGLE AREA, CIRCUMCIRCLE AREA, INSCRIBED AREA)
// values are changed to achive yellow, purple and red areas. 
// variables will not always represent form areas throughout the algorithm.
long double R, r;

int main() {
	while (scanf("%d %d %d ", &A, &B, &C) != EOF) {
		// SEMI PERIMETER 
		SP = (long double) (A + B + C) / 2;
		// TRIANGLE AREA
		TA = sqrt(SP*(SP-A)*(SP-B)*(SP-C));
		// CIRCUMCIRCLE AREA
		R = (long double)A*B*C/(4*TA);
		SA = PI*R*R;
		// YELLOW AREA = CIRCUMCIRCLE AREA - TRIANGLE AREA
		SA = SA - TA;
		// INSCRIBED AREA
		r = TA / SP;
		IA = PI*r*r;
		// PURPLE AREA = AREA OF TRIANGLE - AREA OF INSCRIBED CIRCLE
		TA = TA - IA;
		printf("%0.4Lf %0.4Lf %0.4Lf\n", SA, TA, IA);
	}
	return 0;
}

// References:
// https://en.wikipedia.org/wiki/Heron%27s_formula#Trigonometric_proof_using_the_law_of_cotangents
// https://mathinstructor.net/2012/10/how-to-find-area-of-inscribed-circle-in-a-triangle-with-three-given-sides-of-triangle/
// https://www-formula.com/geometry/radius-circumcircle/all-formulas