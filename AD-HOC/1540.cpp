#include <stdlib.h>
#include <stdio.h>

long long unsigned int A, B;
long long int C, D, V;
int N;

int main() {

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%Lu %Ld %Lu %Ld ", &A, &B, &C, &D);
		V = ((D - B)*100) / (C - A);
		printf("%Ld,%.2Ld\n", V / 100, V % 100);
	}
	return 0;
}