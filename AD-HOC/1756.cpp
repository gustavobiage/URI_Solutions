#include <stdlib.h>
#include <stdio.h>


int T, Q;
long double B, b;
long double area;

int main() {

	while (1) {
		scanf("%d ", &T);
		
		if (!T) {
			break;
		}
		for (int i = 0; i < T; i++) {
			scanf("%d ", &Q);
			scanf("%Lf %Lf ", &b, &B);
			area = Q * (b + B) * 5.0 / 2.0;
			printf("Size #%d:\n", i+1);
			printf("Ice Cream Used: %0.2Lf cm2\n", area);
		}
		printf("\n");
	}
	return 0;
}