#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char text[6000];

char minimize(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	}
	return c;
}

int main() {
	
	int is_ignoring, len;
	int count;
	char last;
	char word[100];

	while (fgets(text, 6000, stdin) != NULL) {
		is_ignoring = 0;
		len = strlen(text);
		last = 0;
		count = 0;
		int index = 0;
		while (sscanf(&text[index], " %s ", word) != EOF) {
			index += strlen(word) + 1;
			if (minimize(word[0]) == minimize(last) && !is_ignoring) {
				is_ignoring = 1;
				count++;
			} else if (minimize(word[0]) != minimize(last) && is_ignoring) {
				is_ignoring = 0;
			}
			last = word[0];
		}
		printf("%d\n", count);
	}

	return 0;
}