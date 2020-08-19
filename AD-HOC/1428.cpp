#include <stdlib.h>
#include <stdio.h>

int m, n;
int t;
int main() {
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d ", &n, &m);
		printf("%d\n", (n/3)*(m/3));
	}
	return 0;
}