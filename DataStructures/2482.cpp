#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

int N, M;

char lang[10000];
char prt[10000];
map<string, string> m;
string strA, strB;

void clean(char * p) {
	int len = strlen(p);
	if (p[len-1] == '\n') {
		p[len-1] = '\0';
		len--;
	}
}

int main() {
	scanf("%d", &N);
	scanf("%*c");
	for (int i = 0; i < N; i++) {
		fgets(lang, 10000, stdin);
		clean(lang);
		fgets(prt, 10000, stdin);
		clean(prt);
		strA = lang;
		strB = prt;
		m[strA] = strB;
	}

	scanf("%d", &M);
	scanf("%*c");

	for (int i = 0; i < M; i++) {
		fgets(lang, 10000, stdin);
		clean(lang);
		fgets(prt, 10000, stdin);
		clean(prt);
		strA = prt;
		printf("%s\n%s\n", lang, m[strA].c_str());
		printf("\n");
	}
	return 0;
}