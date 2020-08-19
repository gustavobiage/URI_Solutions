#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n;
int ehd, epr, other;
char c[100000];

int main() {
	while (scanf("%d ", &n) != EOF) {
		epr = ehd = other = 0;
		for (int i = 0; i < n; i++) {
			scanf("%*s %s ", c);
			if (!strcmp(c, "EPR")) {
				epr++;
			} else if (!strcmp(c, "EHD")) {
				ehd++;
			} else {
				other++;
			}
		}
		printf("EPR: %d\n", epr);
		printf("EHD: %d\n", ehd);
		printf("INTRUSOS: %d\n", other);
	}
	return 0;
}