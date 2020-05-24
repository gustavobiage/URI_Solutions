#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int A, B, C;
long double a, b, c;
int isT;

int isNotTriangle(int a, int b, int c) {
	return a >= b + c || b >= a + c || c >= a + b;
}

int eval(int a, int b, int c) {
	if (a > b && a > c) {
		return a*a - (b*b + c*c);
	} else if (b > a && b > c) {
		return b*b - (a*a + c*c);
	} else if (c > a && c > b) {
		return c*c - (a*a + b*b);
	}
	return -1;
}

int main() {

	scanf("%d %d %d ", &A, &B, &C);

	isT = !isNotTriangle(A, B, C);
	int par;
	if (isT) {
		par = eval(A, B, C);
		if (par == 0) {
			printf("r\n");
		} else if (par < 0) {
			printf("a\n");
		} else if (par > 0) {
			printf("o\n");
		}
	} else {
		printf("n\n");
	}
	return 0;
}