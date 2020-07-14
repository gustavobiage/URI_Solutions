#include <stdlib.h>
#include <stdio.h>

int A;
int tic;

int main() {
	tic = 6;
	while (scanf("%d ", &A) != EOF) {
		if (A%tic) {
			printf("N\n");
		} else {
			printf("Y\n");
		}
	}
	return 0;
}