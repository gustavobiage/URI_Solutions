#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T, c[3];
int pointer, counting;
char line[202];
int mul;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf(" %s ", line);
		counting = pointer = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == 'a' && !counting) {
				counting = 1;
			} else if (line[i] == 'a' && counting) {
				counting++;
			} else {
				if (counting) {
					c[pointer++] = counting;
				}
				counting = 0;
			}
		}
		if (counting) {
			c[pointer++] = counting;
		}

		mul = pointer > 0;
		for (int i = 0; i < pointer; i++) {
			mul = mul * c[i];
		}
		printf("k");
		for (int i = 0; i < mul; i++) {
			printf("a");
		}
		printf("\n");
	}
	return 0;
}