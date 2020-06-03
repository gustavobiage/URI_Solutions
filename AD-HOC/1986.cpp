#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

int N;
map<char, int> m;
char a, b;
int v;

int init() {
	const char * alf = "0123456789ABCDEF";
	int len = strlen(alf);
	for (int i = 0; i < len; i++) {
		m[alf[i]] = i;
	}
}

int main() {
	init();
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c%c ", &a, &b);
		v = m[a]*16 + m[b];
		printf("%c", v);
	}
	printf("\n");
	return 0;
}