#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long double N1, N2, P1, P2;
long double p, q;
int EV1, EV2, AT, D;
int main() {
	while (1) {
		scanf("%d %d %d %d ", &EV1, &EV2, &AT, &D);
		if (!EV1 && !EV2 && !AT && !D) {
			break;
		}

		N1 = ceil((long double)EV1/D);
		N2 = ceil((long double)EV2/D);
		p = (long double)AT / 6;
		q = 1 - p;
		// printf("%0.3Lf %0.3Lf %0.3Lf %0.3Lf\n", N1, N2, p, q);
		if (p != q) {
			// UNFAIR COIN FLIPPING
			if (q != 0) {
				P2 = (1 - pow(p/q, N2)) / (1 - pow(p/q, N1 + N2));
			} else {
				P2 = 1;
			}
		} else {
			// FAIR COIN FLIPPING
			P2 = N2/(N1 + N2);
		}
		P1 = 1.0 - P2;
		printf("%0.1Lf\n", P1*100);
	}
	return 0;
}

// References:
// https://en.wikipedia.org/wiki/Gambler's_ruin