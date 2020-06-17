#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char line[102];

int main() {
	scanf("%d ", &N);
	while (N) {
		scanf(" %s ", line);
		int i = strlen(line) - 1;
		while (i >= 0) {
			if (line[i] >= 'a' && line[i] <= 'z') {
				printf("%c", line[i]);
			}
			i--;
		}
		printf("\n");
		N--;
	}
	return 0;
}