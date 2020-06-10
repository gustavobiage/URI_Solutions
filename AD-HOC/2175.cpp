#include <stdlib.h>
#include <stdio.h>

double I, O, B;

int main() {

	scanf("%lf %lf %lf ", &O, &B, &I);
	if (O < B && O < I) {
		printf("Otavio\n");
	} else if (I < O && I < B) {
		printf("Ian\n");
	} else if (B < O && B < I) {
		printf("Bruno\n");
	} else {
		printf("Empate\n");
	}

	return 0;
}