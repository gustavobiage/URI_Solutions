#include <stdlib.h>
#include <stdio.h>

int v, max;

int main() {
	v = -1;
	max = v;
	while (v) {
		scanf("%d ", &v);
		if (v > max) {
			max = v;
		}
	}
	printf("%d\n", max);
	return 0;
}