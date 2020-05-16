#include <stdlib.h>
#include <stdio.h>

int N;
int c;
int main() {
	c = 0;
	while (1) {
		scanf("%d ", &N);
		if (N == -1) {
			break;
		}
		c++;
		printf("Experiment %d: %d full cycle(s)\n", c, N/2);
	}
	return 0;
}