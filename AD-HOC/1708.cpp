#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int A, B, C;

int main() {

	scanf("%d %d ", &A, &B);
	C = B - A;
	printf("%d\n", (int)ceil((double)B/C));
	return 0;
}