#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T;
int B, E;
char output[100000000];
int pointer;

int main() {
	scanf("%d ", &T);
	while (T) {
		pointer = 0;
		scanf("%d %d ", &B, &E);
		for (int i = B; i <= E; i++) {
			sprintf(&output[pointer], "%d", i);
			pointer = strlen(output);
		}
		printf("%s", output);
		pointer--;
		while (pointer >= 0) {
			printf("%c", output[pointer]);
			pointer--;
		}
		printf("\n");
		T--;
	}
	return 0;
}