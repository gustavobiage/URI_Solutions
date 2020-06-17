#include <stdlib.h>
#include <stdio.h>

char word1[20], word2[20], temp[20];
int p[3], pointer;
int C;

int main() {
	scanf("%d ", &C);
	p[0] = p[1] = 0;
	while (C) {
		scanf(" %s ", word1);
		scanf(" %s ", word2);
		scanf(" %s ", temp);

		pointer = 0;
		for (int i = 0; temp[i] != '\0'; i++) {
			if (temp[i] == '_') {
				p[pointer++] = i;
			}
		}

		if (word1[p[0]] == word2[p[1]] ||
			word2[p[0]] == word1[p[1]]) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
		C--;
	}
	return 0;
}