#include <stdlib.h>
#include <stdio.h>

int n, a, b;
int c;
char op;

int main() {
	scanf("%d ", &n);
	scanf("%d %c %d", &a, &op, &b);
	if (op == '+') {
		c = a + b;
	} else {
		c = a * b;
	}
	if (c <= n) {
		printf("OK\n");
	} else {
		printf("OVERFLOW\n");
	}
	return 0;
}