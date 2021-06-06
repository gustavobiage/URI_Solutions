#include <stdlib.h>
#include <stdio.h>

int A, B, C;
const char * INVALIDO = "Invalido";
const char * EQUILATERO = "Valido-Equilatero";
const char * ESCALENO = "Valido-Escaleno";
const char * ISOCELES = "Valido-Isoceles";

const char * NOT_RECT = "Retangulo: N";
const char * RECT = "Retangulo: S";
const char * rect;

int main() {
	scanf("%d %d %d ", &A, &B, &C);
	if (A*A == B*B + C*C ||
		B*B == A*A + C*C ||
		C*C == A*A+ B*B) {
		rect = RECT;
	} else {
		rect = NOT_RECT;
	}

	if (A + B <= C || A + C <= B || B + C <= A) {
		printf("%s\n", INVALIDO);
	} else if (A == B && B == C) {
		printf("%s\n%s\n", EQUILATERO, rect);
	} else if (A == B || B == C || A == C) {
		printf("%s\n%s\n", ISOCELES, rect);
	} else {
		printf("%s\n%s\n", ESCALENO, rect);
	}
	return 0;
}