#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char word[10000];
int pointer;

int cmp(int index, int diff, int len) {
	for (int i = index; i < index + diff; i++) {
		if (word[i - diff] != word[i]) {
			return 0;
		}
	}
	return 1;
}

void eval(char * word, int first) {
	int len = strlen(word);
	int diff;
	pointer = len/2;
	while (pointer < len) {
		diff = len - pointer;
		if (cmp(pointer, diff, len)) {
			break;
		}
		pointer++;
	}
	if (first || pointer < len) {
		word[pointer] = '\0';
		printf("%s\n", word);
		// Becarefull, debug is wrong (Do not eval the same word multiple times)
		// eval(word, 0);
	}
}

int main() {
	while (scanf(" %s ", word) != EOF) {
		eval(word, 1);
	}

	return 0;
}