#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int qtd;
double m, t, val;
int T, N, D;

int main() {
	scanf("%d ", &T);
	while (T) {
		scanf("%d %d ", &D, &N);
		m = -1;		
		for (int i = 0; i < N; i++) {
			scanf("%lf ", &val);
			qtd = D/val;
			t = D - qtd*val;
			if (val <= D && t > m) {
				m = t;
			}
		}
		printf("%0.2lf\n", fmax(m, 0.0));
		T--;
	}
	return 0;
}