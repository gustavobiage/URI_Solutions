#include <stdlib.h>
#include <stdio.h>

int T;
int C, E;
char op;

int main() {

	while (scanf("%d ", &T) != EOF) {
		for (int i = 0; i < T; i++) {
			scanf("%dx%d ", &C, &E);
			if (E > 2) {
				printf("%dx%d", C*E, E-1);
			} else {
				printf("%dx", C*E);
			}
			if (i+1 < T) {
				scanf("%c ", &op);	
				printf(" %c ", op);
			}
		}
		printf("\n");
	}
	return 0;
}