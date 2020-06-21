#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int T;
char line[2005];
int len, c;
char last;

void eval() {
	if (last == '0') {
		if (c > 2) {
			while (c) {
				int m = fmin(c, 255);
				printf("#%c", (unsigned char) m);
				c -= m;
			}
		} else {
			for (int i = 0; i < c; i++) {
				printf("0");
			}
		}
	} else if (last == ' ') {
		if (c > 2) {
			while (c) {
				int m = fmin(c, 255);
				printf("$%c", (unsigned char) m);
				c -= m;
			}
		} else {
			for (int i = 0; i < c; i++) {
				printf(" ");
			}
		}
	}
}

int main() {
	scanf("%d", &T);
	scanf("%*c");
	while (T--) {
		fgets(line, 2000, stdin);
		len = strlen(line);
		if (line[len-1] == '\n') {
			line[len-1] = '\0';
			len--;
		}
		last = line[0];
		c = 1;
		if (last != '0' && last != ' ') {
			printf("%c", last);
		}
		for (int i = 1; i < len; i++) {

			if (line[i] == last) {
				c++;
			} else {
				eval();
				last = line[i];
				c = 1;
			}
			if (line[i] != '0' && line[i] != ' ') {
				printf("%c", line[i]);
			}
		}
		eval();
		printf("\n");
	}

	return 0;
}