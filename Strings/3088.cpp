#include <stdlib.h>
#include <stdio.h>

char line[100000];
int isPoint(char c) {
	return c == ',' || c == '.';
}
int main() {
	while (fgets(line, 100000, stdin) != NULL) {
		for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
			if (line[i] != ' ' || !isPoint(line[i+1])) {
				printf("%c", line[i]);
			}
		}
		printf("\n");
	}
	return 0;
}