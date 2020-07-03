#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_JOGO "jogo"
#define STR_PERDI "perdi"

int T, t;
char line[100009];
char word[100009];
int pointer;
int max;

void eval() {
	word[pointer] = '\0';
	if (!strcmp(word, STR_JOGO) || !strcmp(word, STR_PERDI)) {
		if (t > max) {
			max = t;
		}
		t = 0;
	}
}

int main() {
	scanf("%d ", &T);
	while (T--) {
		fgets(line, 100009, stdin);
		t = 0;
		pointer = 0;
		max = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] >= 'A' && line[i] <= 'Z') {
				line[i] = line[i] - 'A' + 'a';
				word[pointer++] = line[i];
				t++;
			} else if (line[i] >= 'a' && line[i] <= 'z') {
				word[pointer++] = line[i];
				t++;
			} else {
				eval();
				pointer = 0;
			}
		}
		eval();
		printf("%d\n", max);
	}
	return 0;
}