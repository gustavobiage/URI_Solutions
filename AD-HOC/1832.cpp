#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

map<int, char> m;

int power(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res = res * a;
	}
	return res;
}

int getDecimal(int n) {
	int v;
	int m = 0;
	int c = 0;
	while (n) {
		v = n % 10;
		n = n / 10;
		m += v * power(8, c++);
	}
	return m;
}

void init() {
	m[64] = ' ';
	const char * a = "abcdefghi";
	for (int i = 0; i < strlen(a); i++) {
		m[i+129] = a[i];
	}

	const char * b = "jklmnopqr";
	for (int i = 0; i < strlen(b); i++) {
		m[i+145] = b[i];
	}

	const char * c = "stuvwxyz";
	for (int i = 0; i < strlen(c); i++) {
		m[i+162] = c[i];
	}

	const char * d = "ABCDEFGHI";
	for (int i = 0; i < strlen(d); i++) {
		m[i+193] = d[i];
	}

	const char * e = "JKLMNOPQR";
	for (int i = 0; i < strlen(e); i++) {
		m[i+209] = e[i];
	}

	const char * f = "STUVWXYZ";
	for (int i = 0; i < strlen(f); i++) {
		m[i+226] = f[i];
	}

	const char * g = "0123456789";
	for (int i = 0; i < strlen(g); i++) {
		m[i+240] = g[i];
	}	
}

char line[100000];
char word[100000];
int stack[100000];
int pointer;

int main() {
	init();
	int v;
	while (fgets(line, 100000, stdin) != NULL) {
		pointer = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] != ' ' && (!i || line[i-1] == ' ')) {
				stack[pointer++] = i;
			}
		}

		for (int i = 0; i < pointer; i++) {
			sscanf(&line[stack[i]], " %s ", word);
			v = atoi(word);
			printf("%c", m[getDecimal(v)]);
		}
		printf("\n");
	}

	return 0;
}