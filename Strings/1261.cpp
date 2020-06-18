#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

char line[1000001];
map<string, long long int> m;
string str;
char word[20];
long long int total;
long long int v;
int pointer, M, N;

int main() {

	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s %Ld ", word, &v);
		str = word;
		m[str] = v;
	}

	while (M > 0) {
		fgets(line, 1000001, stdin);
		pointer = 0;
		while (sscanf(&line[pointer], " %s ", word) != EOF) {
			pointer += strlen(word) + 1;
			if (strcmp(word, ".") == 0) {
				printf("%Ld\n", total);
				total = 0;
				M--;
			} else {
				str = word;
				total += m[str];
			}
		}
	}

	return 0;
}