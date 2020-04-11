#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

map<char, char> m;
int N, C;
char k1[50], k2[50];
char text[10000];

void eval(char a, char b) {
	m[a] = b;
	m[b] = a;
}

char captalize(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 'A';
	}
	return c;
}

char minimize(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	}
	return c;	
}

void replace(char * c) {
	if (m.find(captalize(*c)) == m.end()) {
		return;
	}
	
	if (*c >= 'a' && *c <= 'z') {
		//Letter
		*c = minimize(m[captalize(*c)]);
	} else if (*c >= 'A' && *c <= 'Z') {
		*c = m[*c];
	} else {
		*c = minimize(m[*c]);
	}
}

int main() {
	int linebreak = 0;

	while (scanf("%d %d ", &C, &N) != EOF) {

		if (linebreak) {
			printf("\n");
		}

		fgets(k1, 50, stdin);
		fgets(k2, 50, stdin);

		m.clear();

		for (int i = 0; i < C; i++) {
			eval(k1[i], k2[i]);
		}

		for (int j = 0; j < N; j++) {
			fgets(text, 10000, stdin);
			for (int i = 0; i < strlen(text) - 1; i++) {
				replace(&text[i]);
			}
			printf("%s", text);
		}
		linebreak = 1;
	}
	printf("\n");
	return 0;
}