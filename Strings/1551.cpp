#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

int T, len;
char line[100000];
set<char> s;

int main() {

	scanf("%d ", &T);
	while (T) {
		fgets(line, 100000, stdin);
		s.clear();
		len = strlen(line);
		for (int i = 0; i < len; i++) {
			if (line[i] >= 'A' && line[i] <= 'Z') {
				s.insert(line[i] - 'A' + 'a');
			} else if (line[i] >= 'a' && line[i] <= 'z') {
				s.insert(line[i]);
			}
		}

		if (s.size() == 26) {
			printf("frase completa\n");
		} else if (s.size() >= 13) {
			printf("frase quase completa\n");
		} else {
			printf("frase mal elaborada\n");
		}

		T--;
	}
}