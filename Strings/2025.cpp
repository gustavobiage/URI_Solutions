#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char line[102];

int cmp(char * a, const char * b) {
	int i;
	for (i = 1; a[i+1] != '\0' && i < strlen(b) - 1; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return b[i+1] == '\0';
}

int main() {

	scanf("%d ", &N);
	const char * J = "Joulupukki"; 
	while (N) {
		fgets(line, 102, stdin);
		int is_word = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (cmp(&line[i], J)) {
				printf("J");
				i++;
				int c = 0;
				while (c < 8) {
					printf("%c", J[c+1]);
					i++;
					c++;
				}
				printf("i");
			} else {
				printf("%c", line[i]);
			}
		}
		N--;
	}
	return 0;
}