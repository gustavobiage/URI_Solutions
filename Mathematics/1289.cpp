#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N, I, S;
double P, Q, R;
double prob, lastProb;
int f, index;

int main() {
	scanf("%d ", &S);
	while (S--) {
		scanf("%d %lf %d ", &N, &P, &I);
		Q = 1 - P;
		prob = 1;
		f = 1;
		index = 0;
		R = 0;
		while (f || abs(prob - lastProb) > 1e-9) {
			lastProb = prob;
			f = 0;
			if (index+1 == I) {
				R += prob*P;
			}
			prob *= Q;

			index = (index+1)%N;
		}
		printf("%0.4lf\n", R);
	}
	return 0;
}