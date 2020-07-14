#include <stdlib.h>
#include <stdio.h>

int i, f;
int A, G, RA, RG;
double fa, fg;
int mcd;

int cmp(double a, double b) {
	if (abs(a-b) < 0.00001) {
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d.%d ", &i, &f);
	A = i*100 + f;
	scanf("%d.%d ", &i, &f);
	G = i*100 + f;
	scanf("%d.%d ", &i, &f);
	RA = i*100 + f;
	scanf("%d.%d ", &i, &f);
	RG = i*100 + f;

	fa = (double)RA / A;
	fg = (double)RG / G;
	if (cmp(fa, fg) || fg > fa) {
		printf("G\n");
	} else {
		printf("A\n");
	}
	return 0;
}