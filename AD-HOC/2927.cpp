#include <stdlib.h>
#include <stdio.h>

int A, C, X, Y;

int main() {
	scanf("%d %d %d %d ", &A, &C, &X, &Y);
	A++;
	if (C - X - Y >= A) {
		printf("Igor feliz!\n");
	} else {
		if (X > Y/2) {
			printf("Caio, a culpa eh sua!\n");
		} else {
			printf("Igor bolado!\n");
		}
	}
	return 0;
}