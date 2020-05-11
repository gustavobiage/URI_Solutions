#include <stdlib.h>
#include <stdio.h>
#include <vector>

int T;
double pf;
double tpf = 0.0;
int p;
int tp = 0;
char line[10000];

int main() {

	scanf("%d ", &T);
	for (int t = 0; t < T; t++) {

		scanf("%lf ", &pf);
		fgets(line, 10000, stdin);
		p = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == ' ') {
				p++;
			}
		}
		p++;
		tp += p;
		tpf += pf;
		printf("day %d: %d kg\n", t+1, p);
	}
	printf("%0.2lf kg by day\n", (double)tp / T);
	printf("R$ %0.2lf by day\n", tpf / T);

	return 0;
}