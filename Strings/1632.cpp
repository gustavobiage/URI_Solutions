#include <stdlib.h>
#include <stdio.h>

int T;
long long unsigned c;
char line[20];

int is_special(char c) {
	if (c >= 'a' && c <= 'z') {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 's';
	} else if (c >= 'A' && c <= 'Z') {
		return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'S';
	} else if (c >= '0' && c <= '9') {
		return c == '4' || c == '3' || c == '1' || c == '0' || c == '5';
	}
	return 0;
}

int main() {
	scanf("%d ", &T);
	while (T) {
		scanf("%s ", line);
		c = 1;
		for (int i = 0; line[i] != '\0'; i++) {
			if (is_special(line[i])) {
				c *= 3;
			} else {
				c *= 2;
			}
		}

		printf("%Lu\n", c);
		T--;
	}
}