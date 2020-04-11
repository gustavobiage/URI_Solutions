#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string.h>


using namespace std;

map<char, char> m;

char replace(char c) {
	if (m.find(c) != m.end()) {
		return m[c];
	}
	return c;
}

int main() {
	m['@'] = 'a';
	m['&'] = 'e';
	m['!'] = 'i';
	m['*'] = 'o';
	m['#'] = 'u';

	char F[5000];
	int lb = 0;

	while (scanf("%[^\n]%*c", F) != EOF) {

		if (lb) {
			printf("\n");
		}

		for (int i = 0; i < strlen(F); i++) {
			F[i] = replace(F[i]);
		}
		// if (F[strlen(F)-1] == '\n') {
		// 	F[strlen(F)-1] = '\0';
		// }
		printf("%s", F);
		lb = 1;
	}

	printf("\n");
	return 0;
}