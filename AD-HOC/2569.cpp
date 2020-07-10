#include <stdlib.h>
#include <stdio.h>

char ac[1000], bc[1000], cc[1000];
int a, b, c;
char op;

int main() {
	scanf("%s %c %s ", ac, &op, bc);
	for (int i = 0; ac[i] != '\0'; i++) {
		if (ac[i] == '7') {
			ac[i] = '0';
		}
	}
	for (int i = 0; bc[i] != '\0'; i++) {
		if (bc[i] == '7') {
			bc[i] = '0';
		}
	}
	sscanf(ac, "%d", &a);
	sscanf(bc, "%d", &b);
	if (op == '+') {
		c = a + b;
	} else {
		c = a * b;
	}
	sprintf(cc, "%d", c);
	int f = 1;
	for (int i = 0; cc[i] != '\0'; i++) {
		if (cc[i] == '7') {
			cc[i] = '0';
		}
	}
	sscanf(cc, "%d", &c);
	printf("%d\n", c);
}