#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

struct group {
	char v1[100];
	char v2[100];
	char v3[100];
};

int N;
map<string, struct group> m;
struct group g;
string str;
char v[100], aux[100];

int eval(string s, char * p) {
	struct group g = m[s];
	return strcmp(g.v1, p) == 0 ||
		strcmp(g.v2, p) == 0 ||
		strcmp(g.v3, p) == 0;
}

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %s %s ", aux, g.v1, g.v2, g.v3);
		str = aux;
		m[str] = g;
	}

	while (scanf("%s %s ", aux, v) != EOF) {
		str = aux;
		if (eval(str, v)) {
			printf("Uhul! Seu amigo secreto vai adorar o/\n");
		} else {
			printf("Tente Novamente!\n");
		}
	}
	return 0;
}