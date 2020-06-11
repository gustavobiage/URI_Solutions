#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
int len, f;
char word[100000];

int main() {
	scanf("%d ", &N);
	f = 1;
	for (int i = 0; i < N; i++) {
		scanf(" %s ", word);
		len = strlen(word);
		if (f) {
			f = 0;
		} else {
			printf(" ");
		}
		if (len == 3) {
			if (word[0] == 'O' && word[1] == 'B') {
				printf("OBI");
			} else if (word[0] == 'U' && word[1] == 'R') {
				printf("URI");
			} else {
				printf("%s", word);
			}
		} else {
			printf("%s", word);
		}
	}
	printf("\n");
	return 0;
}