#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int N, L, C;
char word[100];
int charCount, lineCount;
int len, f, c;
int main() {
	while (scanf("%d %d %d ", &N, &L, &C) != EOF) {
		f = 1;
		lineCount = charCount = 0;
		for (int i = 0; i < N; i++) {
			scanf(" %s ", word);
			len = strlen(word);
			if (charCount + len + !f <= C) {
				charCount += len + !f;
			} else {
				charCount = len;
				lineCount++;
			}
			f = 0;
		}
		
		lineCount += charCount != 0;
		printf("%d\n", (int)ceil((double)lineCount / L));
	}
	return 0;
}