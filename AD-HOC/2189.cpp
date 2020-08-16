#include <stdlib.h>
#include <stdio.h>

int n, c, v;

int main() {
	c = 0;
	while (1) {
		scanf("%d ", &n);
		if (!n) {
			break;
		}
		c++;
		printf("Teste %d\n", c);
		for (int i = 1; i <= n; i++) {
			scanf("%d ", &v);
			if (v == i) {
				printf("%d\n", i);
			}
		}
		printf("\n");
	}
	return 0;
}