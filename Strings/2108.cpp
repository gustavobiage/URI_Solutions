#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int res[102];
char line[102], word[102];
int pointer, resPointer;
int max, len;
char maxWord[102];

int main() {
	max = -1;
	while (1) {
		fgets(line, 102, stdin);
		if (strcmp(line, "0\n") == 0 || strcmp(line, "0") == 0) {
			break;
		}
		pointer = 0;
		resPointer = 0;
		while (sscanf(&line[pointer], " %s", word) != EOF) {
			len = strlen(word);
			pointer += len + 1;
			res[resPointer++] = len;
			if (len >= max) {
				max = len;
				strcpy(maxWord, word);
			}
		}
		for (int i = 0; i < resPointer; i++) {
			if (i == 0) {
				printf("%d", res[i]);
			} else {
				printf("-%d", res[i]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("The biggest word: %s\n", maxWord);
	return 0;
}