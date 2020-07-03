#include <stdlib.h>
#include <stdio.h>

long long int a, b, c;
char number[10000];

int main() {
	while (1) {
		scanf("%Ld %Ld ", &a, &b);
		if (!a && !b) {
			break;
		}
		c = a + b;
		sprintf(number, "%Ld", c);
		for (int i = 0; number[i] != '\0'; i++) {
			if (number[i] != '0') {
				printf("%c", number[i]);
			}
		}
		printf("\n");
	}
}