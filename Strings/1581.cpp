#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T;
int N;
char word[1000];
char cmp[1000];
int res;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		scanf("%s ", word);
		res = 1;
		for (int i = 0; i < N-1; i++) {
			scanf("%s ", cmp);
			if (strcmp(word, cmp)) {
				res = 0;
			}
		}
		if (res) {
			printf("%s\n", word);
		} else {
			printf("ingles\n");
		}
	}
	return 0;
}