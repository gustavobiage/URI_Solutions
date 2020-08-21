#include <stdlib.h>
#include <stdio.h>

long long int m;
int sum;

int main() {
	while (scanf("%*d %Ld ", &m) != EOF) {
		sum = 0;
		while (m) {
			sum += m % 10;
			m = m / 10;
		}
		if (sum % 3) {
			printf("%d nao\n", sum);
		} else {
			printf("%d sim\n", sum);
		}
	}
	return 0;
}