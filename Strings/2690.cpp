#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int N;
char line[1000000];
char output[1000000];
char word[50];

int pointer;
int prt;
map<char, char> m;

void init() {
	const char * minAlf = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < strlen(minAlf); i++) {
		m[minAlf[i]] = (i % 10) + '0';
	}

	const char * capAlf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int order[] = {6, 8, 7, 5, 2, 3, 0, 9, 1, 4};
	for (int i = 0; i < strlen(capAlf); i++) {
		m[capAlf[i]] = (order[i % 10]) + '0';
	}
}

int main() {
	init();
	scanf("%d ", &N);
	while (N) {
		fgets(line, 1000000, stdin);
		pointer = 0;
		prt = 0;
		while (sscanf(&line[pointer], " %s ", word) != EOF && prt < 12) {
			pointer += strlen(word) + 1;
			for (int i = 0; i < strlen(word); i++) {
				if (word[i] != ' ') {
					output[prt++] = m[word[i]];
				}
			}
		}
		output[prt] = '\0';
		output[12] = '\0';
		printf("%s\n", output);
		N--;
	}
	return 0;
}