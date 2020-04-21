#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char text[200][200];
char formatted[200][200];

int len;
int first, new_word;
int f;

void prt(int i, int max) {
	int len = strlen(formatted[i]);
	for (int j = 0; j < max - len; j++) {
		printf(" ");
	}
}

int is_word(char c) {
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

int get_max() {
	int len;
	int max = 0;
	for (int i = 0; i < N; i++) {
		len = strlen(formatted[i]);
		if (max < len) {
			max = len;
		}
	}
	return max;
}

int main() {
	int first = 1;

	while (1) {
		scanf("%d ", &N);
		if (N == 0)
			break;

		if (first) {
			first = 0;
		} else {
			printf("\n");	
		}

		for (int i = 0; i < N; i++) {
			fgets(text[i], 200, stdin);
		}

		for (int i = 0; i < N; i++) {
			len = strlen(text[i]);
			new_word = 0;
			int index = 0;
			f = 1;

			for (int j = 0; j < len -1; j++) {
				if (new_word) {
					if (is_word(text[i][j]) && !f) {
						formatted[i][index++] = ' ';
						formatted[i][index++] = text[i][j];
						new_word = 0; 
					} else if (is_word(text[i][j]) && f) {
						formatted[i][index++] = text[i][j];
						new_word = 0;
						f = 0;
					}
				} else {
					if (is_word(text[i][j])) {
						f = 0;
						formatted[i][index++] = text[i][j]; 
					} else {
						new_word = 1;
					}
				}
			}
			formatted[i][index++] = '\0';
		}

		int max = get_max();

		for (int i = 0; i < N; i++) {
			prt(i, max);
			printf("%s\n", formatted[i]);
		}
	}

	return 0;
}