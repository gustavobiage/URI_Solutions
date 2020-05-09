#include <stdlib.h>
#include <stdio.h>

long long int a, b;

int main() {

	while (scanf("%Ld %Ld ", &a, &b) != EOF) {

		if (a > b) {
			printf("%Ld\n", a - b);
		} else {
			printf("%Ld\n", b - a);
		}
	}
	return 0;
}