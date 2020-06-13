#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <utility>

using namespace std;

char line[60];
pair<char, char> p[60];
int pointer, f, len;
int res;
const char * COBOL1 = "COBOL";
const char * COBOL2 = "cobol";

int cmp(int i, char c1, char c2) {
	return p[i].first == c1 || p[i].first == c2 ||
	 p[i].second == c1 || p[i].second == c2;
}

int main() {
	while (scanf(" %s ", line) != EOF) {
		f = 1;
		len = strlen(line);
		pointer = 0;
		for (int i = 0; i < len; i++) {
			if (f || line[i-1] == '-') {
				f = 0;
				p[pointer].first = line[i];
			}

			if (i == len-1 || line[i+1] == '-') {
				p[pointer++].second = line[i];
			}
		}
		res = 0;
		for (int i = 0; i < pointer - 4; i++) {
			int j;
			for (j = i; cmp(j, COBOL1[j-i], COBOL2[j-i]) && j-i < 5; j++);
			if (j == i+5) {
				res = 1;
				break;
			}
		}

		if (res) {
			printf("GRACE HOPPER\n");
		} else {
			printf("BUG\n");
		}
	}
	return 0;
}