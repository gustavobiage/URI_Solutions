#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int F1, F2, F3, F[3];
int A, B, s;
int total;

int cmp(const void * a, const void * b) {
	int v1 = *((int *) a);
	int v2 = *((int *) b);
	return v1 - v2;
}

int eval(int A, int B) {
	if (B - A > 200) {
		return (B - A - 200) * 100;
	}
	return 0;
}

int main() {
	scanf("%d %d %d ", &F[0], &F[1], &F[2]);
	qsort(F, 3, sizeof(int), cmp);	
	
	s = F[0]*100;
	
	A = F[0];
	B = F[1];
	s += eval(A, B);
	
	A = F[1];
	B = F[2];
	s += eval(A, B);
	
	A = F[2];
	B = 600;
	s += eval(A, B);
	
	printf("%d\n", s);
	return 0;
}