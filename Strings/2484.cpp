#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char word[102];
int LEN, len;
int f;

int main() {
	while (scanf(" %s ", word) != EOF) {
		LEN = strlen(word);
		len = LEN;
		while (len) {
			for (int j = 0; j < LEN - len; j++) {
				printf(" ");
			}
			f = 1;
			for (int j = 0; j < len; j++) {
				if (f) {
					f = 0;
					printf("%c", word[j]);
				} else {
					printf(" %c", word[j]);
				}
			}
			printf("\n");
			len--;
		}
		printf("\n");
	}

	return 0;
}