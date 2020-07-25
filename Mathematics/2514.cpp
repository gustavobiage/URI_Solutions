#include <stdlib.h>
#include <stdio.h>

int M;
int L1, L2, L3;

int euclides(int a, int b) {
	if (b > a) {
		return euclides(b, a);
	}
	if (!b) {
		return a;
	}
	return euclides(b, a%b);
}

int main() {
	while (scanf("%d ", &M) != EOF) {
		scanf("%d %d %d ", &L1, &L2, &L3);
		int mdc = euclides(L1, L2);
		int mmc = (L1*L2)/mdc;
		mdc = euclides(mmc, L3);
		mmc = (mmc*L3)/mdc;
		printf("%d\n", mmc-M);
	}
	return 0;
}