#include <stdlib.h>
#include <stdio.h>

int N;
int current, counter;
int a, b;

int main() {

	while (scanf("%d ", &N) != EOF) {
		current = 1;
		counter = 0;
		for (int i = 0; i < N-1; i++) {
			scanf("%d %d ", &a, &b);
			if (a > current) {
				current = a;
				counter = (b != 1);
			} else {
				counter += (b == 1);
			}
		}
		printf("%d\n", counter);
	}

	return 0;
}