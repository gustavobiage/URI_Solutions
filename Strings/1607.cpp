#include <stdlib.h>
#include <stdio.h>

int T;
int c;
char word[10009];
char cmp[10009];

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%s %s ", word, cmp);
		c = 0;
		for (int i = 0; word[i] != '\0'; i++) {
			if (word[i] < cmp[i]) {
				c += cmp[i] - word[i];
			} else if (word[i] > cmp[i]) {
				c += 26 - (word[i] - cmp[i]);
			}
		}
		printf("%d\n", c);
	}
	return 0;
}