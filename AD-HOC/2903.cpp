#include <stdlib.h>
#include <stdio.h>

int R1, R2, R;

int gcd(int a, int b) {
	if (a < b) {
		return gcd(b, a);
	}

	if (b == 0) {
		return a;
	}

	return gcd(b, a%b);
}

int main() {

	scanf("%d.%d ", &R1, &R2);
	R = R1*100 + R2;
	if (R > 18000) {
		R = 36000 - R;
	}
	printf("%d\n", 36000 / gcd(36000, R));
	return 0;
}