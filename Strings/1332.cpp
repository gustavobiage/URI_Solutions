#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char word[1001];
const char * ONE = "one";
const char * TWO = "two;";
const char * THREE = "three";

int cmp(const char * pat, char * word) {
	int p1 = 0;
	int p2 = 0;
	int c = 0;
	while (p2 < strlen(pat)) {
		if (pat[p2++] != word[p1++]) {
			c++;
		}
	}
	c += strlen(word) - p1;
	return c;
}

int main() {

	scanf("%d ", &N);
	while (N--) {
		scanf(" %s ", word);

		if (cmp(ONE, &word[0]) <= 1) {
			printf("1\n");
		} else if (cmp(TWO, &word[0]) <= 1) {
			printf("2\n");
		} else if (cmp(THREE, &word[0]) <= 1) {
			printf("3\n");
		}
	}
	return 0;
}