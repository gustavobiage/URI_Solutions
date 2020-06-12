#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

char line[1000000];
set<char> s;
int c;
char ch;

int main() {

	while (scanf(" %s ", line) != EOF) {
		s.clear();
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] >= 'a' && line[i] <= 'z' ||
			 line[i] >= 'A' && line[i] <= 'Z' ||
			 line[i] >= '0' && line[i] <= '9') {
				s.insert(line[i]);
			}
		}
		c = 0;
		while (scanf("%c", &ch) != EOF) {
			if (ch == '\n') {
				break;
			}
			if (s.find(ch) != s.end()) {
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}