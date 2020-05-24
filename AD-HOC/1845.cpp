#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char line[100000];
char c;
int len;
char sub[] = {'s', 'v', 'b', 'z', 'p', 'x', 'j', 'S', 'V', 'B', 'Z', 'P', 'X', 'J'};

int isF(char c) {
	return c == 'f' || c == 'F';
}

int main() {

	while(fgets(line, 100000, stdin) != NULL) {
		len = strlen(line);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < 14; j++) {
				if (sub[j] == line[i]) {
					if (j >= 7) {
						line[i] = 'F';
					} else {
						line[i] = 'f';
					}
					break;
				}
			}
		}

		c = 'a';
		for (int i = 0; i < len; i++) {
			if (!isF(line[i]) || !isF(c)) {
				printf("%c", line[i]);
			}
			c = line[i];	
		}
	}
	return 0;
}