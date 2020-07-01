#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char line[10000];
int len;

char encode(char c) {
	int cap = 0;
	if (c >= 'A' && c <= 'Z') {
		cap = 1;
		c = c - 'A' + 'a';
	}

	if (c >= 'a' && c <= 'z') {
		int n = c- 'a';
		n = (n + 13) % 26;
		c = n + 'a';
	}

	if (cap) {
		c = c - 'a' + 'A';
	}

	return c;
}

int main() {

	while (fgets(line, 10000, stdin) != NULL) {
		len = strlen(line);
		if (line[len-1] == '\n') {
			line[len-1] = '\0';
			len--;
		}
		for (int i = 0; i < len; i++) {
			line[i] = encode(line[i]);
		}
		printf("%s\n", line);
	}

	return 0;
}