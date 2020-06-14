#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BR "<br>"
#define HR "<hr>"

char word[102];
int f, line;
int lastBreak;

int main() {
	f = 1;
	lastBreak = 0;
	while (scanf(" %s ", word) != EOF) {
		if (strcmp(word, BR) == 0) {
			printf("\n");
			f = 1;
			lastBreak = 1;
			line = 0;
		} else if (strcmp(word, HR) == 0) {
			if (!lastBreak) {
				printf("\n");
			}
			printf("--------------------------------------------------------------------------------\n");
			f = 1;
			lastBreak = 1;
			line = 0;
		} else {
			lastBreak = 0;
			line += strlen(word) + !f;
			if (line > 80) {
				line = strlen(word);
				printf("\n");
				f = 1;
			}

			if (f) {
				f = 0;
				printf("%s", word);
			} else {
				printf(" %s", word);
			}
		}
	}
	printf("\n");
	return 0;
}